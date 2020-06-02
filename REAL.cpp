#include "REAL.h"

VAR* REAL::clone(){ // cloner
    VAR* temp =new REAL(name,val); // creating new variable
    return temp;
}


REAL::REAL(string nm,double data){ // constructor
    val=data;
    name=nm;
    type="REAL";
}

double REAL::get_val_real(){ // getting value
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
	double returnVal = val;
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
	return returnVal;
}
void REAL::ASSGN(double data){
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
    val = data;
	lock = 0;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&lockCondition);
}


REAL::operator double() const { return val; } // operator overloading double

//virtual auto getValue()->double{return get_val_real();}


REAL::~REAL(){}
