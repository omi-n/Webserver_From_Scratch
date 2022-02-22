//
// Created by Nabil on 2/22/2022.
//

#include "SimpleServer.h"

using namespace Nabil_Omi_WSL;

SimpleServer::SimpleServer(int domain,
                           int service,
                           int protocol,
                           int port,
                           u_long interface,
                           int backlog_) {
    socket = new ListeningSocket(domain, service, protocol, port, interface, backlog_);
    // Don't need to worry about leaks since the object will stay for the lifetime of the function.
}

SimpleServer::~SimpleServer() {
    delete socket;
}

ListeningSocket *SimpleServer::getSocket() {
    return socket;
}
