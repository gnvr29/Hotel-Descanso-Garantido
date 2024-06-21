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
        ~Cliente();

    private:
        string criaStringDeDados();
        bool pessoaExiste(string identificador);
        int pesquisaDiarias();
        int definePontosDeFidelidade();
        int armazenaDadosEmArquivo(string dados);
};

#endif