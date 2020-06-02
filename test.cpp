
#include "OPERATION.h"
#include "VAR.h"
#include "ADD.h"
#include "SUB.h"
#include "STRING.h"
#include "REAL.h"
#include "NUMERIC.h"
#include "MUL.h"
#include "DIV.h"
#include "CHAR.h"
#include <iostream>

using namespace std;

int main(){
    VAR* NUM1 = new NUMERIC("NUM", 100);
    VAR* STR = new STRING("STR", "LIVE is NOHA");
    VAR* CHR = new CHAR("num1", 'N');
    VAR* CHR2 = new CHAR("num2", 'M');
    VAR* REL = new REAL("num3", 100.5);
    VAR* NUM = NUM1->clone();

    cout<<STR->get_val_str()<<endl;
    STR->SET_STR_CHAR(1,'O');
    cout<<STR->get_val_str()<<endl;

    //CHR->ASSIGN("")
    double xxxxx=*NUM;
    cout<<(double)*REL<<"   xasx  "<<NUM->get_val_num()<<endl;

    ADD X1 (2,NUM,(double)*REL,(double)*NUM);

    cout<<"1: "<<NUM->get_val_num()<<endl;
    SUB X2 (NUM,(double)*REL,(double)5);
    cout<<"2: "<<NUM->get_val_num()<<endl;
    DIV X3 (NUM,(double)*REL,(double)*NUM);
    cout<<"3: "<<NUM->get_val_num()<<endl;
    MUL X4 (2,NUM,(double)*REL,(double)*NUM);
    cout<<"4: "<<NUM->get_val_num()<<endl;


}
