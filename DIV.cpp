#include "DIV.h"
DIV::DIV(){}
void DIV::er(int n,VAR* result,...){ // constructor
    va_list args; // list of all variadic arguments
    va_start(args,result); // starting point of variadic parameters

    try{
        double x =va_arg(args,double); // setting the passed parameter to double
        double y =va_arg(args,double); // setting the passed parameter to double
        if(y!=0){result->ASSGN(x/y);} // handling errors
        else{throw ZeroDiv();}// another error type
    }
        catch(const exception& e){throw nonNumeric("DIV02","one or more of the parameters are non numerical","DIV");} // error type DIV02



}

DIV::~DIV(){}
