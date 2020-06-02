#include "Thread.h"
#include "NUMERIC.h"
#include <iostream>

using namespace std;

void* set(NUMERIC var, double data) {
	var.ASSGN(data);
	cout << var.get_val_real();
}

int main() {
	
	NUMERIC *myNumeric = new NUMERIC("Number", 62);
	/*
	Thread t1([myNumeric] {myNumeric->ASSGN(200); });
	
	Thread t2([myNumeric] {cout << myNumeric.get_val_real(); });
	
	Thread t3([myNumeric] {myNumeric.printVal(); });
	
	*/
}