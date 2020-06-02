#include "MUL.h"
MUL::MUL(){}
void MUL::er(int n,VAR* result,...){ // taking the numbers to perform operation
    va_list args;
    va_start(args,result);
    double res=1;
    try{
        for(int i =0;i<n;i++){
            res*=va_arg(args,double);
        }
    }catch(const exception& e){throw nonNumeric("MUL01","one or more of the parameters are non numerical","MUL");} // handling errors

    result->ASSGN(res);
}

MUL::~MUL(){}
