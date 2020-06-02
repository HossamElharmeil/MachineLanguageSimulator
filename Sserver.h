#ifndef SSERVER_H
#define SSERVER_H
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;


class Server
{
    public:
        Server();
        void hasher(char*);
        int liner(char*);
        bool ifend();
        int process(char*);
        vector <string> lines; // vector of code lines
        void print();
        string item = ""; //vector of lines' items
        hash <string> hsh; // hashing the string
        bool if_hash_equal();
        void setPrevAndCurrent();
        void set_sum();
        bool chk_sum(int);
        virtual ~Server();
    private:
        size_t sum=0;
        size_t current=0;
        size_t hasha=0;
        size_t  prev=0;
        string new_data="";

};

#endif // SERVER_H



