#ifndef NOTDECLARED_H
#define NOTDECLARED_H

#include "MisError.h"


class NotDeclared : public MisError{ // error for no declaration
    public:
        NotDeclared(string , string ,...); // variadic function to fit for any number of parameters
        virtual ~NotDeclared();

    protected:

    private:
};

#endif // NOTDECLARED_H
