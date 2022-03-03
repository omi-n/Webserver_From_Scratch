//
// Created by Nabil on 2/22/2022.
//

#include "WebServer.h"
#include <iostream>
#include <pthread.h>

static volatile bool keep_running = true;
static void* userInput_thread(void*)
{
    while(keep_running) {
        if (std::cin.get() == 'q')
        {
            //! desired user input 'q' received
            keep_running = false;
        }
    }
    return nullptr;
}

int main(int argc, char **argv) {
    pthread_t tId;
    (void) pthread_create(&tId, 0, userInput_thread, 0);

    int port = (int) strtol(argv[1], nullptr,10);

    std::string filePath = "/html_css/example.html";
    Nabil_Omi_WSL::FileParser fileParser(filePath);
    std::string parsed = fileParser.getParsed();

    Nabil_Omi_WSL::Server server(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, 10, parsed);

    while(keep_running) {
        server.launch();
    }
    server.stop();

    (void) pthread_join(tId, 0);
}

