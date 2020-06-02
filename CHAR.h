#ifndef CHAR_H
#define CHAR_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>

#include "VAR.h"

using namespace std;


class CHAR : public VAR{ // inherited class from variables class
    public:
        CHAR(string,char); // constructor

        virtual operator char() const;
        //virtual auto getValue()->char;
        virtual char get_val_char(); // getting character value
        virtual void ASSGN(char); // assigning
        virtual VAR * clone(); // cloner
        virtual ~CHAR(); // destructor

    protected:

    private:
        char val; // char value
        string name; // char name
};

#endif // CHAR_H
