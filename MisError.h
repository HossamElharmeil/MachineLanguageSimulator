#pragma once
#include <string>
#include <iostream>
using namespace std;
class MisError{
protected:
	string errorNumber;
	string category;
	string operation;
	string errorDescription;

public:
	virtual string formattedError()const ;
	MisError();
	~MisError();
};

