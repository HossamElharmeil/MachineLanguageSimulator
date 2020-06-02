#include "STRING.h"

VAR* STRING::clone(){ // cloner to copy variable content into other
    VAR* temp =new STRING(name,val); // creating new variable
    return temp;
}




STRING::STRING(string nm, string data){ // constructor
    if(data.length()<=255)val=data;
    name=nm;
    type="STRING";
}

void STRING::SET_STR_CHAR(int indx,char data){ // getting a char from string
	pthread_mutex_lock(&mutex);
    if(indx<val.length())val[indx]=data;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&lockCondition);
}
STRING::operator string() const{return val;}

//void STRING::SET_STR_CHAR(int indx,STRING other){
//    name[indx]=other.get_val_of(indx);
//}

//virtual auto getValue()->string{return get_val_str();}


string STRING::get_val_str(){ // getting the value of string
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
	string returnVal = val;
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
	return returnVal;
}
void STRING::set_val(string data){ // setting values for string
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
    val=data;
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
}

char STRING::get_val_of(int indx){ // getting value of string
	pthread_mutex_lock(&mutex);
	while (lock == 1) {
		pthread_cond_wait(&lockCondition, &mutex);
	}
	lock = 1;
    char myReturn = val[indx];
	pthread_mutex_unlock(&mutex);
	lock = 0;
	pthread_cond_signal(&lockCondition);
	return myReturn;
}

void STRING::ASSGN(string data){ // assigning string value into other
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

STRING::~STRING(){}
