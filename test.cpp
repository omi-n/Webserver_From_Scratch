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

int main() {
    pthread_t tId;
    (void) pthread_create(&tId, 0, userInput_thread, 0);

    Nabil_Omi_WSL::Server server;

    (void) pthread_join(tId, 0);
}

