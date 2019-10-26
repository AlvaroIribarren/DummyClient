//
// Created by alvaro on 28/9/19.
//

#ifndef CLIENTHONEYPOT_CLIENTPROTOCOL_H
#define CLIENTHONEYPOT_CLIENTPROTOCOL_H


#include "commonSocket.h"
#include <string>

class Protocol {
private:
    Socket clientSocket;
public:
    //Crea el protocolo conectando el socket.
    Protocol(const std::string &portName, const std::string &hostNumber);

    //Envia el mensaje recibido por parametro.
    void send(std::string &message);

    //Recibe un mensaje hasta encontrar un '\n'
    std::string receive();

    //Destructor por default.
    ~Protocol();
};


#endif //CLIENTHONEYPOT_CLIENTPROTOCOL_H
