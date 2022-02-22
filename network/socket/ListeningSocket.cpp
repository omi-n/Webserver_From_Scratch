//
// Created by Nabil on 2/22/2022.
//

#include "ListeningSocket.h"

using namespace Nabil_Omi_WSL;

ListeningSocket::ListeningSocket(int domain,
                                 int service,
                                 int protocol,
                                 int port,
                                 u_long interface,
                                 int backlog_)
        : BindingSocket(domain, service, protocol, port, interface){
    backlog = backlog_;
    startListening();
    testConnection(listening);
}

void ListeningSocket::startListening() {
    listening = listen(getSock(), backlog);
}
