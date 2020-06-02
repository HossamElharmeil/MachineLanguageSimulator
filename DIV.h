#ifndef DIV_H
#define DIV_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>

#include "VAR.h"
#include "OPERATION.h"

using namespace std;

class DIV: public OPERATION{ // inherited class from the operation
    public:
        DIV();
        virtual void er(int,VAR*,...); // constructor
        virtual ~DIV(); // virtual destructor



    private:
};

#endif // DIV_H
