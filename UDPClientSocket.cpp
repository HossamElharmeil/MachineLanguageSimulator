#include "UDPClientSocket.h"
#include <iostream>

UDPClientSocket::UDPClientSocket(): UDPSocket() {} // Invoke UDPSocket constructor
bool UDPClientSocket::initialize(char * _peerAddr, int _peerPort) { // if sock is -1 then it was not initialized before, and so we can create a new socket
    if (sock == -1) sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) return false; // If sock == -1 after invoking the socket system call then and error occured
    struct hostent * hp; //A pointer to a host information structure
    if (_peerAddr != NULL) { // If _peerAddr not equal to NULL then allocate memory and copy its value into peerAddress
        peerAddress = (char * ) calloc(strlen(_peerAddr) + 1, sizeof(char));
        strcpy(peerAddress, _peerAddr);
    } else peerAddress = NULL;
    peerPort = _peerPort; // Set peerPort
    peerAddr.sin_family = AF_INET; // Setup peerAddr
    peerAddr.sin_port = htons(peerPort);
    if (peerAddress != NULL && strcmp(peerAddress, "") != 0) { // if peerAddress has a value then initialize peerAddr
        hp = gethostbyname(peerAddress);
        if(hp)memcpy((char * ) & peerAddr.sin_addr, (char * )hp->h_addr,hp->h_length);
        else memcpy((char * ) & peerAddr.sin_addr, (char * )_peerAddr,20);
        std::cout<<"\n"<<_peerAddr<<"\n";
        enable();
    } else enabled = false; // set socket read/write buffer.
                            std::cout<<"ya rab "<<std::endl;

    int buf_size = SOCKET_READ_BUFFER_SIZE;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char * ) & buf_size, sizeof(int)) == -1) printf("Error: receive buffer\n");
    if (setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char * ) & buf_size, sizeof(int)) == -1) printf("Error: send buffer\n");
                            std::cout<<"ya rab "<<std::endl;


    return true;
}
UDPClientSocket::~UDPClientSocket() {}

