#ifndef VAR_H
#define VAR_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include <iostream>
using namespace std;

class STRING;
class VAR{
    public:
        VAR();
        virtual char get_val(){}
        virtual void ASSGN(double){}
        virtual void ASSGN(string){}

        virtual string getType();
        virtual int64_t get_val_num(){}
        virtual double get_val_real(){}
        virtual operator double() const{}
        virtual operator char() const{}
        virtual operator string() const{}
        virtual string get_val_str(){}
        virtual char get_val_of(int){}
        virtual void SET_STR_CHAR(int,char){}
        virtual void set_val(string){}
        virtual char get_val_char(){}
        virtual VAR * clone(){}

        virtual ~VAR();

    protected:
        string type;

    private:
};

#endif // VAR_H
