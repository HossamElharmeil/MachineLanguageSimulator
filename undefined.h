#ifndef UNDEFINED_H
#define UNDEFINED_H

#include "MisError.h"


class undefined: public MisError{

    public:
        undefined(string,...);
        virtual ~undefined();

    protected:

    private:
};

#endif // UNDEFINED_H
