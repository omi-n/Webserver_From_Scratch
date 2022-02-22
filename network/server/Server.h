//
// Created by Nabil on 2/22/2022.
//

#ifndef WSLWEBSERVER_SERVER_H
#define WSLWEBSERVER_SERVER_H

#include <cstdio>
#include "SimpleServer.h"
#include <iostream>

namespace Nabil_Omi_WSL {

class Server : SimpleServer {

public:
    Server();

    void launch() final;

private:
    char buffer[30000] = {0};
    int new_socket;
    void acceptor() final;
    void handler() final;
    void responder() final;
};

}



#endif //WSLWEBSERVER_SERVER_H
