#pragma once
#include "Thread.h"
#include "MIS.h"
class ThreadMIS : public Thread{
public:
	ThreadMIS(MIS* pmyMIS, vector<string> plines, int* pip);
	virtual void* threadMainBody(void* arg);
private:
	vector<string> lines;
	int* ip;
	MIS * myMIS;
	string* output;
};