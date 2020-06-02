#ifndef NONNUMERIC_H
#define NONNUMERIC_H

#include "MisError.h"


class nonNumeric: public MisError{ // type of error when performing operation on string

    public:
        nonNumeric(string, string,string,...); // constructor
        virtual ~nonNumeric();

    protected:

    private:
};

#endif // NONNUMERIC_H
