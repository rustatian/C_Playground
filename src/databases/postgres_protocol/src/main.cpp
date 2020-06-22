//
// Created by valery on 07/11/2019.
//

#include "../include/main.hpp"
#include "../include/protocol.hpp"

int main() {
    const boost::int_t<32>::exact PROTOCOL_VERSION = (3 << 16);

    Connection conn("127.0.0.1", 5432);
    conn.connect();
    conn.send_startup_message();
}

typedef struct mi_page_s {
    uint8_t segment_idx:1,
} mi_page_t ;