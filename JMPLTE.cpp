#include "JMPLTE.h"



int JMPLTE::goJump(int x, int y)
{
	return x <= y ? true : throw new JMPLTEError();
}

JMPLTE::JMPLTE()
{
}


JMPLTE::~JMPLTE()
{
}
