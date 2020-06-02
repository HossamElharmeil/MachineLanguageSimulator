#include "ThreadMIS.h"

void* ThreadMIS::threadMainBody(void* arg) {
	while (true) {
		if(myMIS->exe(ip, output)) break;
	}
}
ThreadMIS::ThreadMIS(MIS* pmyMIS, vector<string> plines, int* pip) {
	myMIS = pmyMIS;
	lines = plines;
	ip = pip;
}
