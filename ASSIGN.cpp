#include "ASSIGN.h"

ASSIGN::ASSIGN(){}

void ASSIGN::er (int n,VAR* result,...){ // performing assign
    va_list args; // list of all variadic arguments
    va_start(args,result); // starting point of variadic parameters

    string type = result->getType(); // type of the variable

        if(type=="STRING")result->ASSGN(va_arg(args,string)); // checking for type and assign accordingly
        else if(type=="CHAR")result->ASSGN(char(va_arg(args,string)[0]));
        else if(type=="NUMERIC")result->ASSGN(stod(va_arg(args,string)));
        else if(type=="REAL")result->ASSGN(stod(va_arg(args,string)));


}


ASSIGN::~ASSIGN(){}
