#include "JMPLT.h"



int JMPLT::goJump(int x, int y)
{
	return x < y ? true : throw new JMPLTError();
}

JMPLT::JMPLT()
{
}


JMPLT::~JMPLT()
{
}
