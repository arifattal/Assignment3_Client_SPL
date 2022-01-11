//
// Created by ari on 08/01/2022.
//

#include "../include/readKeyboard.h"
#include <iostream>


readKeyboard::readKeyboard(ConnectionHandler *handler, bool &shouldTerminate, bool &threadCondition):handler(handler), shouldTerminate(shouldTerminate), threadCondition(threadCondition){};
//
void readKeyboard::run() {
    while(!shouldTerminate){
        if (threadCondition) { //this condition is initially set to true and set back to true after a message has been received from the server
            const short bufsize = 1024;
            char buf[bufsize];
            std::cin.getline(buf, bufsize);
            std::string line(buf);
            int len = line.length();
            line = line + ";"; //add ; marker to the end of the text received from keyboard
            handler->sendLine(line);
//        if (!handler->sendLine(line)) {
//            std::cout << "Disconnected. Exiting...\n" << std::endl;
//            break;
//        }
            // connectionHandler.sendLine(line) appends '\n' to the message. Therefore we send len+1 bytes.
            std::cout << "Sent " << len + 1 << " bytes to server" << std::endl;
            threadCondition = false; //set value to false. This value will be set back to true by the readSocket task
        }
    }
}
