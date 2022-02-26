//
// Created by Nabil on 2/22/2022.
//

#include "network/server/Server.h"
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

    int port = strtol(argv[1], nullptr,10);

    std::string hardcoded_html = "<html>"
                                 "<body>"
                                 "<h1>Response successfully recieved!</h1>"
                                 "</body>"
                                 "</html>";

    Nabil_Omi_WSL::Server server(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, 10, hardcoded_html);

    while(keep_running) {
        server.launch();
    }
    server.stop();

    (void) pthread_join(tId, 0);
}

