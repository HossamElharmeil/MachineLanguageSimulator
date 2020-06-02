#ifndef SYNTAXERROR_H
#define SYNTAXERROR_H

#include "MisError.h"


class SyntaxError: public MisError{

    public:
        SyntaxError(string,string,...);
        virtual ~SyntaxError();

    protected:

    private:
};

#endif // SYNTAXERROR_H
