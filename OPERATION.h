#ifndef OPERATION_H
#define OPERATION_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include "ZeroDiv.h"
#include "nonNumeric.h"
#include "VAR.h"

using namespace std;

class OPERATION{
    public:
        OPERATION();
        virtual void er (int n,VAR* result,...){} // performing operation
        virtual ~OPERATION(); // destructor

    protected:

    private:
};

#endif // OPERATION_H
