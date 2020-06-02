#include "UDPServerSocket.h"
#include <iostream>
#include "Sserver.h"
#include "MIS.h"
#include "TCPServerSocket.h"
#include "MisError.h"
#include <stdlib.h>     /* calloc, exit, free */
#include Sserver
#define MAX 1514
using namespace std;
int main(){

    char *addr=NULL;


    TCPServerSocket *node=new TCPServerSocket(addr, 9999, MAX);
    Server *ser=new Sserver();
    node->initializeSocket(addr,9999);
    TCPSocket*serve=node->getConnection(0,0,MAX,MAX);
//------------------------------------------
    char*data;
    data=(char*)calloc(MAX,sizeof(char));

//------------------------------------------
	int *ip=new int();
    *(ip)=0;
    string* output= new string();
    *(output)= "";

    MIS* mis=new MIS();


    while (true){
        cout<<"start reading..."<<endl;
        serve->readFromSocket(data,MAX);
        cout<<"stop reading..."<<endl;
        int x=ser->process(data);
        cout<<"x= "<<x<<endl;
        ser->print();
        if(x==1){cout<<"WOW"<<endl;break;}
    }

    auto send = [=](char*res)->void{serve->writeToSocket(res,MAX);};
    mis->lines=ser->lines;
    char*res;
    res=(char*)calloc(MAX,sizeof(char));
    memset(res,0,MAX);


    while(true){

        try{
            bool t = mis->exe(ip,output);
            cout<<t<<endl;
            if(output!=""){
                    cout<<"sending output... ";
                    res[0]='o';
                    for(int x=1;x<5;x++)res[x]=output[x-1];
					serve->writeToSocket(buffer,MAX);
                    cout<<" ...output sent"<<endl;
            }
            if(t){cout<<"end of the file"<<endl;break;}

        }
        catch(const MisError& msg){
            string text=msg.formattedError();
            res[0]='e';
            cout<<"ip "<<*(ip)<<endl;
            output=to_string(*ip)+"    "+text+"\n";
            for(int i=1;i<output->length();i++)res[i]=output[i-1];
            res[output->length()-1]=output[output->length()-1];
            cout<<"sending ERR... ";
			serve->writeToSocket(res,MAX);
            cout<<" ...output sent"<<endl;
            break;
        }
    }
   
    cout<<"Good bye";
    
    
}
