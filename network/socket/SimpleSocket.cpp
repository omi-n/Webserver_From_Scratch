//
// Created by Nabil on 2/22/2022.
//

#include "SimpleSocket.h"

using namespace Nabil_Omi_WSL;

/**
 * Establishes a simple socket. (SHOULD NOT BE USED RAW)
 */
SimpleSocket::SimpleSocket(int domain,
                           int service,
                           int protocol,
                           int port,
                           u_long interface) {
    // Address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // Establish, test socket
    sock = socket(domain, service, protocol);
    testConnection(sock);
}

/**
 * Tests if a socket successfully connected.
 * @param toTest The connection to test
 */
void SimpleSocket::testConnection(int toTest) {
    if(toTest < 0) {
        perror("FAILED TO CONNECT");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in SimpleSocket::getAddress() const {
    return address;
}

int SimpleSocket::getSock() const {
    return sock;
}

int SimpleSocket::getConnection() const {
    return connection;
}

void SimpleSocket::setConnection(int connection_) {
    connection = connection_;
}
