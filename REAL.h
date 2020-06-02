#ifndef REAL_H
#define REAL_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include <pthread.h>

#include "VAR.h"
using namespace std;


class REAL : public VAR{ // variable of type real
    public:
        REAL(string,double); // constructor

        virtual double get_val_real(); // getting the value of variables
        virtual void ASSGN(double); // assigning
        virtual operator double() const; // double operator overloading
        virtual VAR * clone(); //factory strategy

        virtual ~REAL();

    protected:

    private:
        double val;
        string name;
		int lock = 0;
		pthread_mutex_t mutex;
		pthread_cond_t lockCondition;
};

#endif // REAL_H
