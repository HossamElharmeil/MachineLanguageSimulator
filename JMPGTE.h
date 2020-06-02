#pragma once
#include "DoubleJump.h"
#include "JMPGTEError.h"
class JMPGTE :
	public DoubleJump
{
public:

	virtual int goJump(int x, int y);
	JMPGTE();
	~JMPGTE();
};

