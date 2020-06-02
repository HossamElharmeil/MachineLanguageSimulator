#include "SyntaxError.h"

SyntaxError::SyntaxError(string errNum, string errDesc, ...){
    errorNumber=errNum;
    category="syntax";
    operation="NAN";
    errorDescription=errDesc;
}

SyntaxError::~SyntaxError(){}
