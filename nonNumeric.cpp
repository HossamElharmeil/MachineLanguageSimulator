#include "nonNumeric.h"

nonNumeric::nonNumeric(string errNum, string errDesc, string oper,...){ // constructor
    errorNumber=errNum; // error num
    category="Not Decl"; // category of error
    operation=oper; // operation that the error happened on
    errorDescription=errDesc; // error description
}

nonNumeric::~nonNumeric(){} // destructor
