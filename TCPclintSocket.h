#ifndef TCPCLINTSOCKET_H
#define TCPCLINTSOCKET_H
#include "includes.h"
#include "TCPSocket.h"


class TCPclintSocket
{
    public:
        TCPclintSocket(char*, int); // constructor
        bool initializeSocket (); // Initailize client socket
        TCPSocket * makeConnection (int, int); // starting a connection and return a socket that represent the server
        virtual ~TCPclintSocket(); // destructor


    private:
        int sock; // socket number for client
        char * address; // IP address for the client
        int port; // port number for client
        struct sockaddr_in serverAddr;  // Server Socket Address Structure
		struct sockaddr_in clientAddr;  // Client Socket Address Structure
};

#endif // TCPCLINTSOCKET_H
