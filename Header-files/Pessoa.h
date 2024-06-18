#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using namespace std;

class Pessoa {
    private:
        int code;
        string name;
        string phone;

    public:
        virtual int getCode();
        virtual string getName();
        virtual string getPhone();
        virtual void armazenaDadosEmArquivo();
};

#endif 