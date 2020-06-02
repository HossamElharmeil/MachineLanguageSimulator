#include "JMPNZ.h"



JMPNZ::JMPNZ()
{
}


JMPNZ::~JMPNZ()
{
}

int JMPNZ::goJump(int x, int y)
{
	return x != 0 ? true : throw new JMPNZError();
}