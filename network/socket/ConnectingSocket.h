//
// Created by Nabil on 2/22/2022.
//

#ifndef WSLWEBSERVER_CONNECTINGSOCKET_H
#define WSLWEBSERVER_CONNECTINGSOCKET_H

#include "SimpleSocket.h"
#include <cstdio>

namespace Nabil_Omi_WSL {

class ConnectingSocket : public SimpleSocket {

public:
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
    int connectToNetwork(int sock_, struct sockaddr_in address_) final;
};

}



#endif //WSLWEBSERVER_CONNECTINGSOCKET_H
