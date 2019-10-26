//
// Created by alvaro on 28/9/19.
//

#ifndef CLIENTHONEYPOT_COMMONSOCKET_H
#define CLIENTHONEYPOT_COMMONSOCKET_H

#include <string>

class Socket {
private:
    int fd;
public:
    Socket();

    void connectToServer(const std::string& hostName,
                         const std::string& portNumber);

    int send(char *buffer, int messageLength);

    void receive(char *buffer, int length);

    ~Socket();
};


#endif //CLIENTHONEYPOT_COMMONSOCKET_H
