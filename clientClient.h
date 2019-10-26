//
// Created by alvaro on 28/9/19.
//

#ifndef CLIENTHONEYPOT_CLIENTCLIENT_H
#define CLIENTHONEYPOT_CLIENTCLIENT_H


#include <vector>
#include "clientProtocol.h"

class Client {
private:
    Protocol protocol;
public:
    //Crea el cliente con el nombre del host y el numero de puerto
    Client(const std::string& hostName, const std::string& portNumber);

    //Destructor por default;
    ~Client();

    //Loopea la interaccion con el servidor hasta que se ingresa el mensaje
    // QUIT. En este ultimo caso, recibe una ultima vez y se cierra.
    void loopInteraction();
};


#endif //CLIENTHONEYPOT_CLIENTCLIENT_H
