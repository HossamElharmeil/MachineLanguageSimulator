#include <TCPclintSocket.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* calloc, exit, free */
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

#define MAX 1514

void writeErr(char*err,string name) { 
	ofstream stream;
	stream.open(name);
	if (!stream)cout << "cold not creat file";
	for (int i = 1; i < MAX; i++)stream << err[i];
	cout << "err DONE!" << endl;
}
void writeOut(char*out, string name) {
	ofstream stream;
	stream.open(name);
	if (!stream)cout << "cold not creat file";
	for (int i = 1; i < MAX; i++)stream << out[i];
	stream << '\n';
	cout << "err DONE!" << endl;
}
int main(int argc, char** argv){
	cout << "hi there"<<endl;
  
	char *addr=NULL;
	TCPclintSocket* x=new TCPclintSocket (argv[1], 2020);
    TCPSocket*getServed=x->makeConnection(MAX,MAX);
    std::cout<<"File name: "<<argv[2]<< endl;
	vector<string> readFile = getServed->readFromFile(argv[2]);
	std::cout << readFile[0].length() << endl;
	char*data;
	data = (char*)calloc(MAX, sizeof(char));
	cout << "data done" << endl;
	std::cout << argv[1] << endl<<endl;
	int i = 0;
	int j = 0;
	
	
	while (j < readFile.size()) {
		cout << readFile[j] << endl;
		for (; i < readFile[0].length(); i++)data[i] = readFile[j][i];
		for (; i<MAX; i++)data[i] = ' ';
		i = 0;
		cout << "setting data done" << endl;
		std::cout << getServed->writeToSocket(data, MAX) << endl;
		cout << "write to socket done" << endl;
		j++;
	}
	cout << "in read" << endl;
	
	char * data2;
    data2 = (char*)calloc(MAX, sizeof(char));
	
	while (true) {
		getServed->readFromSocket(data2, MAX);
		if (data2[0] == 'o') { 
			cout << "out " << data2[1] << endl;
			writeOut(data2, "try.out");
		}
		else if (data2[0] == 'e') {
			cout << "err " << endl; 
			writeErr(data2,"try.err"); 
			break;

		}
		else break;
	}
	cout << "out read" << endl;

	
	/*b
	UDPServerSocket *serve=new UDPServerSocket();

    serve->initialize(addr,9000);
    std::cout<<serve->readFromSocketWithBlock(data2,MAX);
    //std::cout<<"ya rab "<<serve->isEnabled()<<std::endl;
    for(int i=0;i<MAX;i++)std::cout<<data2[i];
*/
}
