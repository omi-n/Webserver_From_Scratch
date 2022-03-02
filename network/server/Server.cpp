//
// Created by Nabil on 2/22/2022.
//

#include "Server.h"

using namespace Nabil_Omi_WSL;

Server::Server(int domain,
               int service,
               int protocol,
               int port,
               int interface,
               int backlog_,
               std::string &HTMLResponse)
        : SimpleServer(domain, service, protocol, port, interface, backlog_) {
    this->HTMLResponse = HTMLResponse;
}

void Server::acceptor() {
    struct sockaddr_in address = getSocket()->getAddress();
    int addressLength = sizeof(address);
    new_socket = accept(getSocket()->getSock(), (struct sockaddr*)& address, (socklen_t*)& addressLength);
    read(new_socket, buffer, sizeof(buffer));
}

void Server::handler() {
    std::printf("%s", buffer);
}

void Server::responder() {
    std::string response_head = "HTTP/1.1 200 OK\r\n\r\n";
    std::string response_body = HTMLResponse;
    std::string final_response =  response_head + response_body;

    const char* final_response_c_str = final_response.c_str();

    write(new_socket, final_response_c_str, strlen(final_response_c_str));
    close(new_socket);
}

void Server::launch() {
    std::printf("\n========== WAITING ==========\n");
    acceptor();
    handler();
    responder();
    std::printf("========== COMPLETE ==========\n");
}

void Server::stop() {
    close(getSocket()->getSock());
}




