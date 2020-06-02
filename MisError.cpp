#include "MisError.h"



string MisError::formattedError ()const // function to write formated error
{
	//return errorNumber + "	" + category + "	" + operation + "	" + errorDescription + "\n";
    auto adder=[](string addres,string maxLength)->string{ // function to create format
        int lim= maxLength.length()-addres.length();
        string spaces="";
        for(int i=0; i<lim; i++)spaces+=" ";
        return spaces;
    };
    string err=""; // accumulating error format on a string
    err+=errorNumber;
    err+=adder(errorNumber,"Number");
    err+="   ";
    err+=category;
    err+=adder(category,"Category");
    err+="   ";
    err+=operation;
    err+=adder(operation,"Operation");
    err+="   ";
    err+=errorDescription;
    return err;

}

MisError::MisError(){}


MisError::~MisError(){}


