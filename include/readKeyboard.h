//
// Created by ari on 08/01/2022.
//

#ifndef ASSIGNMENT3_CLIENT_SPL_READKEYBOARD_H
#define ASSIGNMENT3_CLIENT_SPL_READKEYBOARD_H
#include "ConnectionHandler.h"
#include <thread>
#include <string>
#include <vector>


class readKeyboard {
    ConnectionHandler *handler;
    bool& shouldTerminate;
    bool& threadCondition; //this is used mainly for correct shutting of the keyboard thread

public:
    readKeyboard(ConnectionHandler *handler, bool &shouldTerminate, bool &threadCondition);
    void run(); //need to be public for running using threads
};


#endif //ASSIGNMENT3_CLIENT_SPL_READKEYBOARD_H
