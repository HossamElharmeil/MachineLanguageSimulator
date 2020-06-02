#include "SUB.h"
SUB::SUB(){}
void SUB::er(int n,VAR* result,...){

    va_list args; // list of all variadic arguments
    va_start(args,result); // starting point of variadic parameters

    try{
        double x =va_arg(args,double); // setting the passed parameter to double
        double y =va_arg(args,double); // setting the passed parameter to double
        result->ASSGN(x-y);
        }
    catch(const exception& e){throw nonNumeric("SUB02","one or more of the parameters are non numerical","SUB");}

}

SUB::~SUB(){}
