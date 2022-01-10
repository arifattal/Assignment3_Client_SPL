//
// Created by ari on 08/01/2022.
//

#include "../include/readSocket.h"
#include <iostream>

readSocket::readSocket(ConnectionHandler *handler, bool &shouldTerminate, bool &threadCondition):handler(handler), shouldTerminate(shouldTerminate), threadCondition(threadCondition){};
//
void readSocket::run(){
    int len = 0;
    while(!shouldTerminate){
        std::string answer;
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!handler->getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }

        len=answer.length();
        // A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
        // we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout  << answer << std::endl;
        if (answer == "ACK 3") {
            std::cout << "Exiting...\n" << std::endl;
            shouldTerminate = true;
        }
        else{
            threadCondition = true;
        }
    }
    std::cout << "readSocket thread finished his job" << std::endl;
};
