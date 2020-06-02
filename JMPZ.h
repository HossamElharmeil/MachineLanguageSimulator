#pragma once
#include "JMPZError.h"

#include "SingleJump.h"
class JMPZ :
	public SingleJump
{
	virtual int goJump(int x, int y);
public:
	JMPZ();
	~JMPZ();
};

