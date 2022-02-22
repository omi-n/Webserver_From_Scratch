//
// Created by Nabil on 2/22/2022.
//

#include "ConnectingSocket.h"

using namespace Nabil_Omi_WSL;

ConnectingSocket::ConnectingSocket(int domain,
                                   int service,
                                   int protocol,
                                   int port,
                                   u_long interface)
        : SimpleSocket(domain, service, protocol, port, interface) {
    setConnection(connectToNetwork(getSock(), getAddress()));
    testConnection(getConnection());
}

int ConnectingSocket::connectToNetwork(int sock_, struct sockaddr_in address_) {
    return connect(sock_, (struct sockaddr *)& address_, sizeof (address_));
}