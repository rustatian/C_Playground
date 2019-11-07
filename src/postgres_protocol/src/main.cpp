//
// Created by valery on 07/11/2019.
//

#include "../include/main.hpp"
#include "../include/protocol.hpp"

int main() {
    Connection conn("127.0.0.1", 5432);
    conn.connect();
}