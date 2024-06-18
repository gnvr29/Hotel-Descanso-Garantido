#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
using namespace std;

class Cliente: public Pessoa {
    private:
        string endereco;
        int pontosDeFidelidade;

    public:
        Cliente(int code, string name, string phone, string endereco);

        //Getters
        int getCode();
        string getName();
        string getPhone();
        string getEndereco();
        int getPontosDeFidelidade();

        //Metodos da classe
        void definePontosDeFidelidade();
        void armazenaDadosEmArquivo();
};

#endif