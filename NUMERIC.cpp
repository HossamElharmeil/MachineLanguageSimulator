#include "NUMERIC.h"
#include <iostream>

VAR* NUMERIC::clone(){ // cloner
    VAR* temp =new NUMERIC(name,val); // creating new variable
    return temp;
}


NUMERIC::NUMERIC(string nm,int64_t data){ // constructor
    val=data;
    name=nm;
    type="NUMERIC";

}
int64_t NUMERIC::get_val_num(){
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
	int64_t returnVal = val;
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
    return returnVal;
}
double NUMERIC::get_val_real(){
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
void NUMERIC::ASSGN(double data){
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
    val = data;
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
}
void NUMERIC::printVal() {
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
	std::cout << val << endl;
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
}

//virtual auto getValue()->int64_t{return get_val_num();}

NUMERIC::operator double() const { return static_cast<double>(val); }


NUMERIC::~NUMERIC(){}
