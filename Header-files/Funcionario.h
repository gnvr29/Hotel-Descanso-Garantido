#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"
using namespace std;

class Funcionario: public Pessoa {
    private:
        string cargo;
        float salary;
    
    public:
        Funcionario(string name, string phone, string cargo, float salary);
        ~Funcionario();
        
    private:
        string criaStringDeDados();
        bool pessoaExiste(string identificador);
        int armazenaDadosEmArquivo(string dados);
};

#endif