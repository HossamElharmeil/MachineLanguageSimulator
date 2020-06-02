#ifndef SUB_H
#define SUB_H
//#include <bits/stdc++.h>
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>

#include "OPERATION.h"

using namespace std;


class SUB : public OPERATION{
    public:
        SUB();
        virtual void er(int,VAR*,...);
        virtual ~SUB();

    protected:

    private:
};

#endif // SUB_H
