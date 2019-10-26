//
// Created by alvaro on 10/10/19.
//

#ifndef CLIENTHONEYPOT_COMMONCLOSEDSOCKET_H
#define CLIENTHONEYPOT_COMMONCLOSEDSOCKET_H

#include <exception>

class SocketError : public std::exception {
public:
    const char* what(){
        return "Socket cerrado";
    }
};

#endif //CLIENTHONEYPOT_COMMONCLOSEDSOCKET_H
