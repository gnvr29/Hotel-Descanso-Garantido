#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Pessoa {
    protected:
        static int contador;
        int code;
        string name;
        string phone;

    public:
        Pessoa();
        virtual bool pessoaExiste(string identificador);
        virtual string criaStringDeDados();
        virtual int armazenaDadosEmArquivo();
};

#endif 