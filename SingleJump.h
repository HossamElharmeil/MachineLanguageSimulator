#pragma once
#include "Jump.h"
class SingleJump :
	public Jump
{
public:
	SingleJump();
	~SingleJump();

	virtual int goJump(int x, int y) = 0;
};

