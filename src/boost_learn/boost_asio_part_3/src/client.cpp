//
// Created by valery on 11/3/19.
//

#include <memory>
#include <string_view>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <utility>
#include <boost/asio/write.hpp>
#include <boost/asio/basic_streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include "../include/client.hpp"
#include <iostream>
#include <boost/asio/streambuf.hpp>
#include <boost/core/noncopyable.hpp>
#include <mutex>

// SYNC CLIENT
class SyncTCPClient {
public:
    SyncTCPClient(const std::string &raw_ip_address, unsigned short port_num) :
            ep_(boost::asio::ip::address::from_string(raw_ip_address), port_num),
            sock_(ioc_) {

        sock_.open(ep_.protocol());
    }

    void connect() {
        sock_.connect(ep_);
    }

    void close() {
        sock_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
        sock_.close();
    }

    std::string emulateLongComputationOp(unsigned int duration_sec) {
        std::string request = "EMULATE_LONG_COMP_OP" + std::to_string(duration_sec) + "\n";

    }

private:
    void sendRequest(const std::string &request) {
        boost::asio::write(sock_, boost::asio::buffer(request));
    }

    std::string receiveResponse() {
        boost::asio::basic_streambuf buf;
        boost::asio::read_until(sock_, buf, "\n");

        std::istream input(&buf);

        std::string response;
        std::getline(input, response);
        return response;
    }

private:
    boost::asio::io_context ioc_;
    boost::asio::ip::tcp::endpoint ep_;
    boost::asio::ip::tcp::socket sock_;
};

size_t sync_client_run() {
    const std::string raw_ip_address = "127.0.0.1";
    const unsigned short port_num = 3333;

    try {
        SyncTCPClient client(raw_ip_address, port_num);

        // Sync connect.
        client.connect();

        std::cout << "Sending request to the server... "
                  << std::endl;

        std::string response =
                client.emulateLongComputationOp(10);

        std::cout << "Response received: " << response
                  << std::endl;

        // Close the connection and free resources.
        client.close();
    }
    catch (boost::system::system_error &e) {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
}

// ASYNC CLIENT
// callback
typedef void(*Callback)(
        unsigned int request_id,
        const std::string &response,
        const boost::system::error_code &ec);

struct Session {
    Session(boost::asio::io_context &ioc, const std::string &raw_ip_address, unsigned short port_num,
            std::string request, unsigned int id, Callback callback) :
            m_sock(ioc),
            m_ep(boost::asio::ip::address::from_string(raw_ip_address), port_num),
            m_request(std::move(request)),
            m_id(id),
            m_callback(callback),
            m_was_cancelled(false) {}


    boost::asio::ip::tcp::socket m_sock;
    boost::asio::ip::tcp::endpoint m_ep;
    std::string m_request;

    boost::asio::streambuf m_response_buf;
    std::string m_response;

    boost::system::error_code m_ec;

    unsigned int m_id; //unique id

    Callback m_callback;

    bool m_was_cancelled;
    std::mutex m_cancel_guard;
};

class AsyncTCPClient : public boost::noncopyable {
public:
    AsyncTCPClient() {
        m_work = std::make_unique<boost::asio::io_context::work>(m_ioc);
        m_thread = std::make_unique<std::thread>([this]() {
            m_ioc.run();
        });
    }

    void emulateLongComputationOp(
            unsigned int duration_sec,
            const std::string &raw_ip_address,
            unsigned short port_num,
            Callback callback,
            unsigned int request_id
    ) {
        // prepare the req string
        std::string request = "EMULATE_LONG_CALC_OP "
                              + std::to_string(duration_sec)
                              + "\n";

        std::shared_ptr<Session> session =
                std::shared_ptr<Session>(new Session(
                        m_ioc,
                        raw_ip_address,
                        port_num,
                        request,
                        request_id,
                        callback));

        // add new session to the list of active session
        std::unique_lock<std::mutex> lock(m_active_session_guard);
        m_active_sessions[request_id] = session;
        lock.lock();

        session->m_sock.async_connect(
                session->m_ep,
                [this, session](const boost::system::error_code &ec) {
                    if (ec.value() != 0) {
                        session->m_ec = ec;
                        onRequestComplete(session);
                        return;
                    }
                    std::unique_lock<std::mutex> cancel_lock(session->m_cancel_guard);

                    if (session->m_was_cancelled) {
                        onRequestComplete(session);
                        return;
                    }

                    boost::asio::async_write(session->m_sock,
                            boost::asio::buffer(session->m_request),
                            [this, session](const boost::system::error_code &ec,
                                    std::size_t bytes_transferred) {
                       if (ec.value() != 0) {
                           session->m_ec = ec;
                           onRequestComplete(session);
                           return;
                       }

                       std::unique_lock<std::mutex> cancel_lock(session->m_cancel_guard);

                       if(session->m_was_cancelled) {
                           onRequestComplete(session);
                           return;
                       }

                       boost::asio::async_read_until(session->m_sock, session->m_response_buf,
                               '\n',
                               [this, session](const boost::system::error_code &ec, std::size_t bytes_transferred) {
                           if (ec.value() != 0) {
                               session->m_ec = ec;
                           } else {
                               std::istream strm(&session->m_response_buf);
                               std::getline(strm, session->m_response);
                           }
                           onRequestComplete(session);
                       });
                    });
                }
        );

    }

    void cancelRequest(unsigned int request_id) {
        std::unique_lock<std::mutex> lock(m_active_session_guard);

        auto it = m_active_sessions.find(request_id);
        if(it != m_active_sessions.end()) {
            std::unique_lock<std::mutex> cancel_lock(it->second->m_cancel_guard);

            it->second->m_was_cancelled = true;
            it->second->m_sock.cancel();
        }
    }

    void close() {
        // destroy work object
        m_work.reset(NULL);

        // wait for the io thread to exit
        m_thread->join();
    }

private:
    void onRequestComplete(std::shared_ptr<Session> session) {
        // shutting down the connection. This method may fail in case
        // socket is not connected

        boost::system::error_code ignored_ec;


        session->m_sock.shutdown(
                boost::asio::ip::tcp::socket::shutdown_both,
                ignored_ec
        );

        // remove the session from the map of active sessions
        std::unique_lock<std::mutex> lock(m_active_session_guard);

        auto it = m_active_sessions.find(session->m_id);
        if (it != m_active_sessions.end()) {
            m_active_sessions.erase(it);
        }


        lock.unlock();

        boost::system::error_code ec;
        if (session->m_ec.value() == 0 && session->m_was_cancelled) {
            ec = boost::asio::error::operation_aborted;
        } else {
            ec = session->m_ec;
        }

        session->m_callback(session->m_id, session->m_response, ec);
    }


    boost::asio::io_context m_ioc;
    std::map<int, std::shared_ptr<Session>> m_active_sessions;
    std::mutex m_active_session_guard;
    std::unique_ptr<boost::asio::io_context::work> m_work;
    std::unique_ptr<std::thread> m_thread;
};


int main() {


}