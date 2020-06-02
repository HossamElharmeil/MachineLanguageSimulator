#include "JMPZ.h"





int JMPZ::goJump(int x, int y)
{

	return x == 0 ? true : throw new JMPZError();
	
}

JMPZ::JMPZ()
{
}


JMPZ::~JMPZ()
{
}
