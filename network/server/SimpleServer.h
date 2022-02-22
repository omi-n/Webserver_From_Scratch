//
// Created by Nabil on 2/22/2022.
//

#ifndef WSLWEBSERVER_SIMPLESERVER_H
#define WSLWEBSERVER_SIMPLESERVER_H

#include <cstdio>
#include <cstring>
#include "../webserver_networking.h"
#include <unistd.h>

namespace Nabil_Omi_WSL {

class SimpleServer {

public:
    SimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog_);
    ~SimpleServer();
    ListeningSocket* getSocket();
    virtual void launch() = 0;

private:
    ListeningSocket* socket;

    virtual void acceptor() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;

};

}


#endif //WSLWEBSERVER_SIMPLESERVER_H
