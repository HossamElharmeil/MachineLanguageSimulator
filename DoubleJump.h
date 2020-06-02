#pragma once
#include "Jump.h"
class DoubleJump :
	 public Jump
{

public:
	virtual int goJump(int x, int y) = 0;
	DoubleJump();
	~DoubleJump();
};

