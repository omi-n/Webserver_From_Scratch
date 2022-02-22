//
// Created by Nabil on 2/22/2022.
//

#ifndef WSLWEBSERVER_LISTENINGSOCKET_H
#define WSLWEBSERVER_LISTENINGSOCKET_H

#include <cstdio>
#include <cstdlib>

#include "BindingSocket.h"

namespace Nabil_Omi_WSL {

class ListeningSocket: public BindingSocket {

public:
    ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog_);
    void startListening();

private:
    int backlog;
    int listening;

};

}


#endif //WSLWEBSERVER_LISTENINGSOCKET_H
