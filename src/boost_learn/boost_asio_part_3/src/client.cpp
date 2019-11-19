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
#include <thread>

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
        return request;
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
        m_work = std::make_unique<boost::asio::io_context::work>(m_ios);

        m_thread = std::make_unique<std::thread>([this]() {
            m_ios.run();
        });
    }

    void emulateLongComputationOp(
            unsigned int duration_sec,
            const std::string &raw_ip_address,
            unsigned short port_num,
            Callback callback,
            unsigned int request_id) {

        // Preparing the request string.
        std::string request = "EMULATE_LONG_CALC_OP "
                              + std::to_string(duration_sec)
                              + "\n";

        std::shared_ptr<Session> session =
                std::make_shared<Session>(
                        m_ios,
                        raw_ip_address,
                        port_num,
                        request,
                        request_id,
                        callback);

        session->m_sock.open(session->m_ep.protocol());

        // Add new session to the list of active sessions so
        // that we can access it if the user decides to cancel
        // the corresponding request before it completes.
        // Because active sessions list can be accessed from
        // multiple threads, we guard it with a mutex to avoid
        // data corruption.
        std::unique_lock<std::mutex>
                lock(m_active_sessions_guard);
        m_active_sessions[request_id] = session;
        lock.unlock();

        session->m_sock.async_connect(session->m_ep,
                                      [this, session](const boost::system::error_code &ec) {
                                          if (ec.value() != 0) {
                                              session->m_ec = ec;
                                              onRequestComplete(session);
                                              return;
                                          }

                                          std::unique_lock<std::mutex>
                                                  cancel_lock(session->m_cancel_guard);

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

                                                                       std::unique_lock<std::mutex>
                                                                               cancel_lock(session->m_cancel_guard);

                                                                       if (session->m_was_cancelled) {
                                                                           onRequestComplete(session);
                                                                           return;
                                                                       }

                                                                       boost::asio::async_read_until(session->m_sock,
                                                                                                     session->m_response_buf,
                                                                                                     '\n',
                                                                                                     [this, session](
                                                                                                             const boost::system::error_code &ec,
                                                                                                             std::size_t bytes_transferred) {
                                                                                                         if (ec.value() !=
                                                                                                             0) {
                                                                                                             session->m_ec = ec;
                                                                                                         } else {
                                                                                                             std::istream strm(
                                                                                                                     &session->m_response_buf);
                                                                                                             std::getline(
                                                                                                                     strm,
                                                                                                                     session->m_response);
                                                                                                         }

                                                                                                         onRequestComplete(
                                                                                                                 session);
                                                                                                     });
                                                                   });
                                      });
    };

    // Cancels the request.
    void cancelRequest(unsigned int request_id) {
        std::unique_lock<std::mutex>
                lock(m_active_sessions_guard);

        auto it = m_active_sessions.find(request_id);
        if (it != m_active_sessions.end()) {
            std::unique_lock<std::mutex>
                    cancel_lock(it->second->m_cancel_guard);

            it->second->m_was_cancelled = true;
            it->second->m_sock.cancel();
        }
    }

    void close() {
        // Destroy work object. This allows the I/O thread to
        // exits the event loop when there are no more pending
        // asynchronous operations.
        m_work.reset(nullptr);

        // Wait for the I/O thread to exit.
        m_thread->join();
    }

private:
    void onRequestComplete(const std::shared_ptr<Session>& session) {
        // Shutting down the connection. This method may
        // fail in case socket is not connected. We don’t care
        // about the error code if this function fails.
        boost::system::error_code ignored_ec;

        session->m_sock.shutdown(
                boost::asio::ip::tcp::socket::shutdown_both,
                ignored_ec);

        // Remove session form the map of active sessions.
        std::unique_lock<std::mutex>
                lock(m_active_sessions_guard);

        auto it = m_active_sessions.find(session->m_id);
        if (it != m_active_sessions.end())
            m_active_sessions.erase(it);

        lock.unlock();

        boost::system::error_code ec;

        if (session->m_ec.value() == 0 && session->m_was_cancelled)
            ec = boost::asio::error::operation_aborted;
        else
            ec = session->m_ec;

        // Call the callback provided by the user.
        session->m_callback(session->m_id,
                            session->m_response, ec);
    };

private:
    boost::asio::io_context m_ios;
    std::map<int, std::shared_ptr<Session>> m_active_sessions;
    std::mutex m_active_sessions_guard;
    std::unique_ptr<boost::asio::io_context::work> m_work;
    std::unique_ptr<std::thread> m_thread;
};

void handler(unsigned int request_id, const std::string &response, const boost::system::error_code &ec) {
    if (ec.value() == 0) {
        std::cout << "Request #" << request_id
                  << " has completed. Response: "
                  << response << std::endl;
    } else if (ec == boost::asio::error::operation_aborted) {
        std::cout << "Request #" << request_id
                  << " has been cancelled by the user."
                  << std::endl;
    } else {
        std::cout << "Request #" << request_id
                  << " failed! Error code = " << ec.value()
                  << ". Error message = " << ec.message()
                  << std::endl;
    }
}

int async_client_invoke() {
    try {
        AsyncTCPClient client;

        // Here we emulate the user's behavior.

        for(int i = 0; i <= 100; ++i) {
            client.emulateLongComputationOp(2, "127.0.0.1", 3333,
                                            handler, 1);
        }
        // User initiates a request with id 1.
//        client.emulateLongComputationOp(2, "127.0.0.1", 3333,
//                                        handler, 1);
        // Then does nothing for 5 seconds.
//        std::this_thread::sleep_for(std::chrono::seconds(5));
        // Then initiates another request with id 2.
        client.emulateLongComputationOp(2, "127.0.0.1", 3334,
                                        handler, 2);
        // Then decides to cancel the request with id 1.
//        client.cancelRequest(1);
        // Does nothing for another 6 seconds.
//        std::this_thread::sleep_for(std::chrono::seconds(6));
        // Initiates one more request assigning ID3 to it.
        client.emulateLongComputationOp(2, "127.0.0.1", 3335,
                                        handler, 3);
        // Does nothing for another 15 seconds.
//        std::this_thread::sleep_for(std::chrono::seconds(15));
        // Decides to exit the application.
        client.close();
    }
    catch (boost::system::system_error &e) {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
}


int main() {
    async_client_invoke();
}