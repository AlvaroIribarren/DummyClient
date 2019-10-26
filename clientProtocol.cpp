//
// Created by alvaro on 28/9/19.
//

#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <netinet/in.h>
#include "clientProtocol.h"

#define SIZE_ONE 1
#define FIRST_POSITION 0
#define END_OF_LINE '\n'
#define FOUR_BYTES 4

Protocol::Protocol(const std::string& portName, const std::string& hostNumber){
    this->clientSocket.connectToServer(portName, hostNumber);
}

void Protocol::send(std::string& message) {
    int messageLength = message.size();

    uint32_t number = htonl(messageLength);
    char *numberBuffer = (char*)&number;

    this->clientSocket.send(numberBuffer, FOUR_BYTES);
    const char* messagePtr = message.c_str();
    this->clientSocket.send(const_cast<char *>(messagePtr), messageLength);
}

std::string Protocol::receive() {
    int32_t ret = 0;
    char *data = (char*)&ret;

    //Recibo longitud en bytes.
    clientSocket.receive(data, FOUR_BYTES);
    sscanf(data, "%d", &ret);
    int sizeIncoming = ntohl(ret);

    std::vector<char> vector(sizeIncoming);
    std::string auxiliar (vector.begin(), vector.end());
    char* buffer = const_cast<char *>(auxiliar.c_str());
    clientSocket.receive(buffer, sizeIncoming);

    std::string message(buffer);

    return message;
}

Protocol::~Protocol()= default;