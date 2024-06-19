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
        string getEndereco();
        int getPontosDeFidelidade();

    private:
        string criaStringDeDados();
        bool pessoaExiste(string identificador);
        int pesquisaDiarias();
        int definePontosDeFidelidade();
        void armazenaDadosEmArquivo(string dados);
};

#endif