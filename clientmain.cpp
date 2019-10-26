#include <vector>
#include "clientProtocol.h"
#include "clientClient.h"
#include "commonClosedSocket.h"

#define HOST_NAME_POSITION 1
#define PORT_NUMBER_POSITION 2

int main(int argc, char *argv[]) {
    try {
        const std::string hostName = std::string(argv[HOST_NAME_POSITION]);
        const std::string portNumber = std::string(argv[PORT_NUMBER_POSITION]);

        Client client(hostName, portNumber);

        client.loopInteraction();
    } catch(const std::exception &e) {
         printf("ERROR: %s", e.what());
    } catch(...) {
        printf("Error desconocido");
    }

    return 0;
}