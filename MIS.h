#ifndef MIS_H
#define MIS_H
#include <stdint.h>
#include <string>
#include <map>
#include <stdarg.h>
#include <iostream>
#include <fstream>
#include "VAR.h"
#include "NUMERIC.h"
#include "CHAR.h"
#include "STRING.h"
#include "REAL.h"
#include "OPERATION.h"
#include "ADD.h"
#include "MUL.h"
#include "SUB.h"
#include "DIV.h"
#include <typeinfo>
#include "MisError.h"
#include "SyntaxError.h"
#include <stdlib.h>
#include <ctype.h>
#include "undefined.h"
#include <sstream>
#include <string>
#include "Jump.h"
#include "JMPZ.h"
#include "JMPNZ.h"
#include "JMPGT.h"
#include "JMPGTE.h"
#include "JMPLTE.h"
#include "JMPLT.h"
#include <chrono>
#include <thread>
#include "ASSIGN.h"
#include "Thread.h"
#include "ThreadMIS.h"

using namespace std;


class MIS{
    public:
        MIS();
        ~MIS();
        void split(string); // split the words on line
        void getLabel(); // getting a label
        void setFIles(string); // creating files
        void operatr(string);
        void jumper(string); // perform jump
        void varImplementer(string, string, string, string); // creating variables and add them to the map
        void writeErr(MisError); // writing on error file
        void writeOut(string*); // writing on output file
        bool exe(int*,string*); // executing process
        bool isThere(string); // checking if variable is on map
        void stringOP();
        double getVarINT(string);
        VAR* getVar(string);
        vector<string>lines;
		virtual void * threadMainBody(void * arg);


    protected:

    private:
        string words[14];
        int parsNum=0;
        int* ip;
		int thread = 0;
        map<string,int>labels;
        map<string,VAR*>vars;
        map<string,OPERATION*> opes;
        map<string,VAR*> maker; // map of <variable type , pointer to a variable>
        map<string,int>whereToGo;
        map<string,Jump*>JMPs;
		

};

#endif // MIS_H
