//
// Created by Nabil on 2/22/2022.
//

#include "BindingSocket.h"

using namespace Nabil_Omi_WSL;

BindingSocket::BindingSocket(int domain,
                             int service,
                             int protocol,
                             int port,
                             u_long interface)
        : SimpleSocket(domain, service, protocol, port, interface) {
    setConnection(connectToNetwork(getSock(), getAddress()));
    testConnection(getConnection());
}

int BindingSocket::connectToNetwork(int sock_, struct sockaddr_in address_) {
    return bind(sock_, (struct sockaddr *)& address_, sizeof (address_));
}