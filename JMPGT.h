#pragma once
#include "DoubleJump.h"
#include "JMPGTError.h"
class JMPGT :
    public DoubleJump
{
public:
	virtual int goJump(int x, int y);
	JMPGT();
	~JMPGT();
};

