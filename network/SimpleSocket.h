//
// Created by Nabil on 2/22/2022.
//

#ifndef WSLWEBSERVER_SIMPLESOCKET_H
#define WSLWEBSERVER_SIMPLESOCKET_H

#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>

namespace Nabil_Omi_WSL {

/**
 * SHOULD NOT BE USED AS-IS. USE AS A BASE CLASS.
 */
class SimpleSocket {

public:
    // Constructor
    SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
    // Connect to the network, should be implemented on higher level.
    virtual int connectToNetwork(int sock, struct sockaddr_in address) = 0;
    // Testing if the connection was successful
    static void testConnection(int toTest);

    // Constant member functions
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
