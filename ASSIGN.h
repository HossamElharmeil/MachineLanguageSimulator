#ifndef ASSIGN_H
#define ASSIGN_H

#include "OPERATION.h"


class ASSIGN:public OPERATION{ // assigning .. inherited from operation
    public:
        ASSIGN();
        virtual void er (int n,VAR* result,...); // variadic function to take different number of parameters according to variable
        virtual ~ASSIGN();

    protected:

    private:
};

#endif // ASSIGN_H
