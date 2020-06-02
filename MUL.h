#ifndef MUL_H
#define MUL_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>

#include"VAR.h"
#include"OPERATION.h"

using namespace std;

class MUL: public OPERATION{ // operation of type multiplication
    public:
        MUL();
        virtual void er(int,VAR*,...); // performing mul
        virtual ~MUL(); // destructor

    protected:

    private:
};

#endif // MUL_H
