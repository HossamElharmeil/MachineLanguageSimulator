#ifndef ZERODIV_H
#define ZERODIV_H

#include "MisError.h"


class ZeroDiv: public MisError{ // error for dividing by zero

    public:
        ZeroDiv();
        virtual ~ZeroDiv();

    protected:

    private:
};

#endif // ZERODIV_H
