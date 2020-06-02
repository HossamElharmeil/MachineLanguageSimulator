#include "UDPSocket.h"
#ifndef UDPSERVERSOCKET_H
#define UDPSERVERSOCKET_H

class UDPServerSocket: public UDPSocket {
public: UDPServerSocket (); // Constructor
    // Initialize socket to reserve connections and data on _addr and _myport
    bool virtual initialize (char * _addr, int _myPort);
    ~UDPServerSocket ( ); // Destructor
};
#endif // UDPSERVERSOCKET_H
