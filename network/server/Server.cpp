//
// Created by Nabil on 2/22/2022.
//

#include "Server.h"

using namespace Nabil_Omi_WSL;

Server::Server() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10) {
    launch();
}

void Server::acceptor() {
    struct sockaddr_in address = getSocket()->getAddress();
    int addressLength = sizeof(address);
    new_socket = accept(getSocket()->getSock(), (struct sockaddr*)& address, (socklen_t*)& addressLength);
    read(new_socket, buffer, sizeof(buffer));
}

void Server::handler() {
    std::printf("%s\n", buffer);
}

void Server::responder() {
    char* hello = (char*) "Hello from server";
    write(new_socket, hello, strlen(hello));
    close(new_socket);
}

void Server::launch() {
    while(true) {
        std::printf("\n========== WAITING ==========\n");
        acceptor();
        handler();
        responder();
        std::printf("========== COMPLETE ==========\n");
        if(std::cin.get() == 'q')
            break;
    }
    close(getSocket()->getSock());
}


