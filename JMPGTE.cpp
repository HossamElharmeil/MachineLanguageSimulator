#include "JMPGTE.h"





int JMPGTE::goJump(int x, int y)
{
	return x >= y ? true : throw new JMPGTEError();
}

JMPGTE::JMPGTE()
{
}


JMPGTE::~JMPGTE()
{
}
