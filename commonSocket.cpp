//
// Created by alvaro on 28/9/19.
//

#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include "commonSocket.h"
#include "commonClosedSocket.h"

Socket::Socket() {
    this->fd = 0;
}


void Socket::connectToServer(const std::string& hostName,
                             const std::string& portNumber){
    struct addrinfo hints;
    int s = 0;
    struct addrinfo *ai_list;
    struct addrinfo *ptr;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    char* host = const_cast<char *>(hostName.c_str());
    char* port = const_cast<char *>(portNumber.c_str());
    s = getaddrinfo(host, port, &hints, &ai_list);
    if (s != 0){
        throw std::runtime_error("Error en la operacion getaddrInfo");
    }
    bool connected = false;
    for (ptr = ai_list; ptr != NULL && !connected; ptr = ptr->ai_next) {
        this->fd =
                socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (this->fd == -1){
            throw std::runtime_error("Error: File descriptor invalido");
        }

        s = connect(this->fd, ptr->ai_addr, ptr->ai_addrlen);
        if (s == -1){
            throw std::runtime_error("Error al conectarse al servidor");
        }
        connected = (s != -1);
    }
    freeaddrinfo(ai_list);
}


int Socket::send(char *buffer, int messageLength){
    int bytesSent = 0;
    while (messageLength > 0){
        bytesSent = ::send(this->fd, buffer, messageLength, 0);
        if (bytesSent < 0){
            throw SocketError();
        }
        buffer += bytesSent;
        messageLength -= bytesSent;
    }
    return 0;
}


void Socket::receive(char *buffer, int length){
    int r = 0;

    while (length > 0){
        r = ::recv(this->fd, buffer, length, 0);
        if (r == 0)
            throw SocketError();
        if (r == -1)
            throw SocketError();

        buffer += r;
        length -= r;
    }
}

Socket::~Socket() {
    shutdown(this->fd, SHUT_RDWR);
    close(this->fd);
}