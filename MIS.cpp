#include "MIS.h"
#define prametars getVarINT(words[3]),getVarINT(words[4]),getVarINT(words[5]),getVarINT(words[6]),getVarINT(words[7]),getVarINT(words[8]),getVarINT(words[9]),getVarINT(words[10]),getVarINT(words[11]),getVarINT(words[12]),getVarINT(words[13])
#define prametarsAll getVar(words[1]),getVar(words[2]),getVar(words[3]),getVar(words[4]),getVar(words[5]),getVar(words[6]),getVar(words[7]),getVar(words[8]),getVar(words[9]),getVar(words[10]),getVar(words[11]),getVar(words[12]),getVar(words[13])

// macros to be replaced when needed in order not to write the command many times

MIS::MIS(){
    whereToGo["OUT"]=0; // setting keys and values to the map for making it easier when parsing the instructions
    whereToGo["ADD"]=1;
    whereToGo["DIV"]=1; // when the value is one then it must be variable and so on
    whereToGo["MUL"]=1;
    whereToGo["SUB"]=1;
    whereToGo["ASSIGN"]=1;
    whereToGo["JMP"]=2;
    whereToGo["JMPZ"]=2;
    whereToGo["JMPNZ"]=2;
    whereToGo["JMPGT"]=2;
    whereToGo["JMPLT"]=2;
    whereToGo["JMPGTE"]=2;
    whereToGo["JMPLTE"]=2;
    whereToGo["VAR"]=3;
    whereToGo["SLEEP"]=4;
    whereToGo["SET_STR_CHAR"]=5;
    whereToGo["GET_STR_CHAR"]=5;
	whereToGo["THREAD_BEGIN"] = 6;
	whereToGo["THREAD_END"] = 6;

    opes["ADD"]=new ADD (); // creating new different operations adding them to the map of operation to be accessed later
    opes["MUL"]=new MUL ();
    opes["DIV"]=new DIV ();
    opes["SUB"]=new SUB ();
    opes["ASSIGN"]=new ASSIGN();

    JMPs["JMP"]=new Jump(); // creating new jump objects adding them to the map of objects
    JMPs["JMPZ"]=new JMPZ();
    JMPs["JMPNZ"]=new JMPNZ();
    JMPs["JMPGTE"]=new JMPGTE();
    JMPs["JMPGT"]=new JMPGT();
    JMPs["JMPLTE"]=new JMPLTE();
    JMPs["JMPLT"]=new JMPLT();


    //declared

} // constructor

double MIS::getVarINT(string data){ // function to get the data of the objects ..
    try{
       return getVar(data)->get_val_real(); // returning the value of the variables or constant value
    }catch(const MisError& e){
        try{if(data=="")return 1;return stod (data);} // if the string is empty return 1
        catch(const exception& x){throw e;}// if it does not work throw error
    }
}

bool MIS::exe(int *i, string* output){ // function to parse and execute
    ip=i;
    cout<<"ip ..MIS .. "<<*ip << endl;
    getLabel(); // getting all the labels
    string command; // declaring to be used
    string line=lines[*ip];

    split(line); // splitting the line into words
    command=words[0]; // first word on the line
    //cout<<*ip<<"-"<<line<<"-"<<command<<endl;
	if (command == "THREAD_BEGIN") {
		*ip++;
		ThreadMIS myMISThread = new ThreadMIS(*this, lines, ip);
		myMISThread.start();
		thread = 1;
		return false;
	}
	if (command == "THREAD_END") {
		if (thread == 0) {
			return true;
		}
		thread = 0;
	}
	if (thread = 0) {
		if (whereToGo.find(command) != whereToGo.end()) { // searching for command on the map
			if (whereToGo[command] == 0) { writeOut(output); } // checking the map value and perform operations according to the number .. this is the reason for creating the map on the constructor
			else if (whereToGo[command] == 1) { operatr(command); }
			else if (whereToGo[command] == 2) { jumper(command); }
			else if (whereToGo[command] == 3) {
				if (words[1][0] == '$')varImplementer(words[2], words[1], words[3], words[4]); //checking if the line starts with $ then deal with it as variable
				else throw SyntaxError("SYN01", "Syntax Error in decelerating var " + words[1] + "   must begin with $"); // if not starting with $ and is variable throw syntax error
				//cout<<vars[words[1]]<<"DFSA"<<endl;
			}
			else if (whereToGo[command] == 4) { this_thread::sleep_for(chrono::milliseconds(stoi(command))); } // performing sleep when the command value on the map = 4
			else if (whereToGo[command] == 5) { stringOP(); }
		}
		else if (command != "LABEL") { throw undefined(words[0]); } // handling errors
	}
	*ip += 1;
    return *ip==lines.size();
}


void MIS::stringOP(){ //string operations
    char a;
    int x;
    if(isThere(words[2]))x=getVarINT(words[2]); // checking if the variable is on the map .. if yes put its value on x
    else x=stod(words[2]); // if no then its a constant .. put it on x
    if(isThere(words[3])&& getVar(words[2])->getType()=="CHAR")a=getVar(words[2])->get_val_char(); // if the variable is char put its value on a
    else if(isThere(words[3])&& getVar(words[2])->getType()=="STRING")a=getVar(words[2])->get_val_of(x);
    else a=char(words[3][0]);
    getVar(words[1])->SET_STR_CHAR(x,a);
}

bool MIS::isThere(string x){try{getVar(x);return 1;}catch(const MisError& e){return 0;}} // trying to get the variable .. if could not throw error

void MIS::operatr(string oper){  // performing operation on string


    string type= getVar(words[1])->getType();
    if(isThere(words[2])){
        if(type=="STRING")opes[oper]->er(parsNum-1,getVar(words[1]),string(*getVar(words[2])),prametars);
        else if(type=="CHAR")opes[oper]->er(parsNum-1,getVar(words[1]),char(*getVar(words[2])),prametars);
        else if(type=="NUMERIC")opes[oper]->er(parsNum-1,getVar(words[1]),double(*getVar(words[2])),prametars);
        else if(type=="REAL")opes[oper]->er(parsNum-1,getVar(words[1]),double(*getVar(words[2])),prametars);
    }else{opes[oper]->er(parsNum-1,getVar(words[1]),words[2],prametars);}
}


void MIS::writeOut(string* output){ // writing on output file
    for(int i =1;i<parsNum;i++){ // looping on the parameters passed to the constructor
        VAR* result=getVar(words[i]); // adding values to the results
        //cout<<"result .. write out  "<<result<<endl;
        string type = result->getType();
        cout<<"typ "<<type<<endl;
        if(type=="STRING")*(output)+=result->get_val_str();
        else if(type=="CHAR")*(output)+=result->get_val_char();
        else if(type=="NUMERIC")*(output)+=to_string(result->get_val_num());
        else if(type=="REAL")*(output)+=to_string(result->get_val_real());
        cout << "value :"<< to_string(result->get_val_real()) << endl;
        cout << "out puuuut  " << *(output)<< endl;
        *(output)+=" ";
    }
}

VAR* MIS::getVar(string name){ // getting the name
    if(vars.find(name) != vars.end()){return vars[name];} // if in map return its name
    else throw SyntaxError("SYN02",name); // if not .. throw error

    } // getting the variable

void MIS::varImplementer (string type, string name, string value, string length="-1"){ // function to create new variable

    string txt = value;
    try{ // handling errors
        double num = stoi(value);
        maker.insert(pair<string,VAR*>("NUMERIC",new NUMERIC(name,num))); // creating new variable of type numeric
        maker.insert(pair<string,VAR*>("REAL",new REAL(name,num))); // creating new variable of type real
    }
    catch(const exception& e){
        maker.insert(pair<string,VAR*>("CHAR",new CHAR(name,*(new char[value.size()+1])))); // creating new variable of type char
        maker.insert(pair<string,VAR*>("STRING",new STRING(name,txt))); // creating new variable of type string
    }

    VAR* data= maker[type]; // adding variable to the map
    vars.insert(pair<string,VAR*>(name,data->clone())); // inserting variable cloner to the variables map

}

void MIS::jumper(string jmp){ // performing jump
    if(labels.find(words[1])!=labels.end()){ // checking if the label exist
        if (JMPs[words[0]]->goJump(getVarINT(words[2]),getVarINT(words[3]))){ // selecting the type of jump
            ip[0]=labels[words[1]]; // setting position for instruction pointer
        }
    }
}




void MIS::getLabel(){ // getting the label
    string line;
    auto xx=[] (const string& str) -> string { // lambda function to remove spaces from lines
         size_t first = str.find_first_not_of(' ');
        if (string::npos == first)
        {
            return "";
        }
         size_t last = str.find_last_not_of(' ');

        return str.substr(first, (last - first + 1));
    };
    string x="";
    int localIp=0;
    while(localIp<lines.size()) { // getting its lines
        split(line); // splitting the lines
        if(words[0]=="LABEL"){ // checking if first word is label
            labels.insert(pair<string,int>(words[1],localIp)); // add the label to the map of labels
        }
        localIp++;
    }
}

void MIS::split(string x){ // function to split words on any line
    int conter = 0;
    int n=0;
    int limit=0;
    x+=" ";
    for(int i=0;i<14;i++)words[i]=""; // looping by index by max 14 word ..
    for(int n=0;n<x.length();n++){
       char test =x[n];
       if(test == ' ' || test == ','){ // splitting when seeing a space or a ,
            conter++;
            limit++;
            continue;
        }

        words[conter] += x[n];
        if(limit==13)break;

    }

    parsNum=limit; // passed parameters numbers to be set as limit for looping*/
}

MIS::~MIS(){} // destructor


