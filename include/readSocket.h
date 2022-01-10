//
// Created by ari on 08/01/2022.
//

#ifndef ASSIGNMENT3_CLIENT_SPL_READSOCKET_H
#define ASSIGNMENT3_CLIENT_SPL_READSOCKET_H
#include "ConnectionHandler.h"
#include <thread>
#include <string>
#include <vector>


class readSocket {
    ConnectionHandler *handler;
    bool& shouldTerminate;
    bool& threadCondition;


public:
    readSocket(ConnectionHandler *handler, bool &shouldTerminate, bool &threadCondition);
    void run();
};


#endif //ASSIGNMENT3_CLIENT_SPL_READSOCKET_H
