#include "ADD.h"
#include <iostream>
ADD::ADD(){}
void ADD::er(int n,VAR* result,...){ // constructor that takes integer to represent the number of passed parameters, and a variadic number of parameters
    va_list args; // list of all variadic arguments
    va_start(args,result); // starting point of variadic parameters
        cout<<result->get_val_real()<< endl;
    double res=0; // accumulator to sum the parameters on
    for(int i =0;i<n;i++){ // looping on the parameters passed to the constructor
        try{ // to handle errors
            double x =va_arg(args,double); // setting the passed parameter to double
             res+=x; // accumulating
        }catch(const exception& e){throw nonNumeric("ADD02","one or more of the parameters are non numerical","ADD");} // error of kind ADD02 , contain the error message


        //std::cout<<fixed<<res<<endl;

    }
    va_end(args);
    result->ASSGN(res); // assigning what is on the accumulator to the result
}

ADD::~ADD(){} // destructor
