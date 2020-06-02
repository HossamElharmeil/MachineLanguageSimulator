#ifndef NUMERIC_H
#define NUMERIC_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include <pthread.h>

#include "VAR.h"
using namespace std;

class REAL;

class NUMERIC : public VAR{ // variable of type numeric
    public:
        NUMERIC(string,int64_t); // constructor
        virtual int64_t get_val_num(); // getting values numbers
        virtual double get_val_real();
        virtual void ASSGN(double);
        virtual operator double() const;
        virtual VAR * clone(); // cloner
		virtual void printVal();

        //virtual auto getValue()->int64_t;



        virtual ~NUMERIC();

    protected:

    private:
        int64_t val;
        string name;
		int lock = 0;
		pthread_mutex_t mutex;
		pthread_cond_t lockCondition;
};

#endif // NUMERIC_H
