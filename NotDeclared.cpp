#include "NotDeclared.h"

NotDeclared::NotDeclared(string errNum, string errDesc, ...){ // constructor

    errorNumber=errNum; // numbering the error
    category="Not Decl";// category of the error
    operation="NAN"; // operation that caused the error
    errorDescription=errDesc; // describing the error
}

NotDeclared::~NotDeclared(){}
