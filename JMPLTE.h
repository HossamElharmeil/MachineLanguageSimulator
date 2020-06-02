#pragma once
#include "DoubleJump.h"
#include "JMPLTEError.h"
class JMPLTE :
	virtual public DoubleJump
{
public:
	virtual int goJump(int x, int y);
	JMPLTE();
	~JMPLTE();
};

