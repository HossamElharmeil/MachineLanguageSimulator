#pragma once
#include "JMPNZError.h"
#include "SingleJump.h"
class JMPNZ :
	public SingleJump
{
public:
	JMPNZ();
	~JMPNZ();

	virtual int goJump(int x, int y);
};

