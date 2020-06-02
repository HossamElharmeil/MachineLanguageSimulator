#include "undefined.h"

undefined::undefined(string errDesc,...){

    errorNumber="UN01";
    category="syntax";
    operation="NAN";
    errorDescription=errDesc+"is an known command";

}

undefined::~undefined(){}
