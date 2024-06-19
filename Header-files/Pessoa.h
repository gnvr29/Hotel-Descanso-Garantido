#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <fstream>

using namespace std;

class Pessoa {
    protected:
        static int contador;
        int code;
        string name;
        string phone;

    protected:
        Pessoa();
        int getCode();
        string getName();
        string getPhone();
        virtual void armazenaDadosEmArquivo();
};

#endif 