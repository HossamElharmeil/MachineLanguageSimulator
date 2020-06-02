#include "TCPclintSocket.h"
#define MAX 1024
#include <iostream>
using namespace std;

TCPclintSocket::TCPclintSocket(char* addr, int portt){
   if (addr != NULL && strcmp (addr,"") != 0){ // if there is an address .. allocate memory for it
		address = (char *) calloc (strlen(addr)+1,sizeof(char));
		memset (address,0,strlen(addr)+1);
		strcpy (address,addr); // set address
	}
	else {
        address= NULL; // set address to null
	}
    port = portt; // Set port number
    memset(&serverAddr, '0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
}

//-------------------------------------------------------------------------------------------------------------------

TCPSocket* TCPclintSocket::makeConnection(int readBufferSize,int writeBufferSize){
    int newsock=0;
    if ((newsock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return NULL;
    }

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, address, &serverAddr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return NULL;
    }

    if (connect(newsock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("\nConnection Failed \n");
        return NULL;
    }
    TCPSocket * tcpSocket = new TCPSocket(newsock,(char *)inet_ntoa(serverAddr.sin_addr),serverAddr.sin_port,readBufferSize,writeBufferSize);
    return tcpSocket;


}
//--------------------------------------------------------------------------------------------------------------------
TCPclintSocket::~TCPclintSocket(){
    shutdown (sock,SHUT_RDWR);  // Shutdown the server read/write channels
	close (sock);              // Close socket descriptor
	if ( address != NULL ) free (address); // free the address buffer
}

int main(int argc, char** argv){

TCPclintSocket* x=new TCPclintSocket (argv[1], 2020);
TCPSocket*n=x->makeConnection(MAX,MAX);
char *buffer;
buffer=(char*)calloc(MAX,sizeof(char));
memset(buffer,51,MAX);
n->writeToSocket(buffer,MAX);

cout<<buffer[0];
}
