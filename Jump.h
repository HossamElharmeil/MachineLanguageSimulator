#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Jump{

public:
	Jump();
	~Jump();

	virtual int goJump(int x , int y);
};
