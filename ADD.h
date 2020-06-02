#ifndef ADD_H
#define ADD_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>

#include "OPERATION.h"
#include "VAR.h"
using namespace std;

class ADD : public OPERATION{ // inherited class from the operation class

    public:
        ADD();
        virtual void er(int,VAR*,...); // variedic constructor
        virtual ~ADD(); // virtual destructor

    protected:

    private:
};

#endif // ADD_H
