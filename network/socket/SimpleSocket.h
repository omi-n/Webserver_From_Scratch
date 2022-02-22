//
// Created by Nabil on 2/22/2022.
//

#ifndef WSLWEBSERVER_SIMPLESOCKET_H
#define WSLWEBSERVER_SIMPLESOCKET_H

#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>

namespace Nabil_Omi_WSL {

/**
 * SHOULD NOT BE USED AS-IS. USE AS A BASE CLASS.
 */
class SimpleSocket {

public:
    SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
    virtual int connectToNetwork(int sock_, struct sockaddr_in address_) = 0;
    static void testConnection(int toTest);

    // Setters
    void setConnection(int connection_);

    // Getters
    struct sockaddr_in getAddress() const;
    int getSock() const;
    int getConnection() const;

private:
    struct sockaddr_in address;
    int sock;
    int connection;
};

}




#endif //WSLWEBSERVER_SIMPLESOCKET_H
