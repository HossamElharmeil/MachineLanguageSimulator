#ifndef STRING_H
#define STRING_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include <pthread.h>

#include "VAR.h"
using namespace std;

class STRING : public VAR{
    public:

        STRING(string, string); // constructor
        virtual string get_val_str(); // getting value of string
        virtual char get_val_of(int); // getting value of char
        virtual void SET_STR_CHAR(int,char);
        virtual operator string() const;
        //void SET_STR_CHAR(int,STRING);
        //void GET_STR_CHAR(int,STRING);
        virtual void set_val(string);
        virtual void ASSGN(string);
        virtual VAR * clone();
        virtual ~STRING();


    protected:

    private:
		
        string val;
        string name;
		int lock = 0;
		pthread_mutex_t mutex;
		pthread_cond_t lockCondition;

};

#endif // STRING_H
