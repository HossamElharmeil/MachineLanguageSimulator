#include "CHAR.h"

VAR* CHAR::clone(){ // cloner
    VAR* temp =new CHAR(name,val); // creating new object
    return temp; // returning the object
}


CHAR::CHAR(string nm,char data){ // constructor
    val=data; // setting to data
    name=nm; // setting to name
    type="CHAR";
}
char CHAR::get_val_char(){ // function for getting character value
    return val;
}
void CHAR::ASSGN(char data){ // assigning
    val = data;
}

CHAR::operator char() const{return val;}



//virtual auto getValue()->char{return get_val_char();}

CHAR::~CHAR(){}
