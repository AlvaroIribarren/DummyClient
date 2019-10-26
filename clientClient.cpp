//
// Created by alvaro on 28/9/19.
//

#include <iostream>
#include <algorithm>
#include "clientClient.h"
#include "commonClosedSocket.h"
#include <string>

#define QUIT_STRING "QUIT"
#define END_OF_LINE '\n'
#define COMA_CHAR ','

Client::Client(const std::string& hostName, const std::string& portNumber):
                                 protocol(hostName, portNumber){}

Client::~Client() = default;

void Client::loopInteraction() {
    bool quitMessage = false;
    std::string message;

    try {
        while (std::getline(std::cin, message)) {
            quitMessage = message == QUIT_STRING;
            protocol.send(message);

            if (quitMessage)
                break;
        }
    } catch (SocketError &c) {
    }
}



