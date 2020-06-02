#pragma once
#include "DoubleJump.h"
#include "JMPLTError.h"
class JMPLT :
	public DoubleJump
{
public:

	virtual int goJump(int x, int y);
	JMPLT();
	~JMPLT();
};