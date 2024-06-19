#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
using namespace std;

class Cliente: public Pessoa {
    private:
        string endereco;
        int pontosDeFidelidade;

    public:
        Cliente(string name, string phone, string endereco);

        //Getters
        string getEndereco();
        int getPontosDeFidelidade();

        //Metodos da classe
    private:
        int definePontosDeFidelidade();
        void armazenaDadosEmArquivo();
};

#endif