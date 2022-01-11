#include <stdlib.h>
#include <ConnectionHandler.h>
#include <thread>

#include "readSocket.h"
#include "readKeyboard.h"
#include <mutex>

//
/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*///
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);
    
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }

    bool shouldTerminate = false; //this value is sent by reference to both threads so that we can shut them simultaneously
    bool threadCondition = true; //start the condition at true, so that the readKeyboard thread can run correctly through it's first while cycle

    readKeyboard keyboardTask(&connectionHandler, shouldTerminate, threadCondition);
    readSocket socketTask(&connectionHandler, shouldTerminate, threadCondition);

    std::thread keyboardThread(&readKeyboard::run, &keyboardTask);
    std::thread socketThread(&readSocket::run, &socketTask);

    socketThread.join();
    keyboardThread.join();

    return 0;
}
