#include "JMPGT.h"



int JMPGT::goJump(int x, int y)
{

	return x > y ? true : throw new JMPGTError();

}

JMPGT::JMPGT()
{
}


JMPGT::~JMPGT()
{
}
