#include "Sserver.h"
#include <stdlib.h>
Server::Server(){}

int Server::process(char* data){
   //hasher(new_data);
   setPrevAndCurrent();
   set_sum();
   return liner(data);
}

void Server::hasher(char* dat){
     for (int i=0; i<1514; i++){
        if (*(dat+i)=='\\' && *(dat+i+1)=='o')break;
        else {new_data.append(1,*(dat+i));}
    }
    hasha = hsh(new_data);
    }
void Server::set_sum(){(sum+=current);}

void Server::setPrevAndCurrent(){prev=current;current=hasha;}

int Server::liner(char* msg){
    for (int i=0; i<1514; i++){
        if (*(msg+i)=='\n'){
            lines.push_back(item);
            item="";
        }else if (*(msg+i)=='\\' && *(msg+i+1)=='o'){
            lines.push_back(item);
            item="";
            return 1;
        }else if (*(msg+i)!='\n') item.append(1,*(msg+i));
    }
    //cout << 2<< endl;
    return 2;
}

void Server::print(){for (int i=0; i< lines.size(); i++){cout<<lines[i]<<endl;}}

bool Server::if_hash_equal(){return (current==prev && current!=0);}

bool Server::chk_sum(int x){return (x==sum);}

Server::~Server(){
}

/*
int main (){

char*da;
    da=(char*)calloc(1514,sizeof(char));
    string d= "nohaxnmagdyxnalibjwkewweeejj ekek";
    da= &d[0];
    //cout << *(da+1);
    Server *ser= new Server();
    ser->process(da);
    ser->print();
    ser->liner(da);
    //cout <<"nooooooooooooo"<< ser->lines[0]<<ser->lines[1]<< endl;
    cout << "hash :  "<< ser->hasha << endl;
    cout << ser->hasha-20;


}*/
