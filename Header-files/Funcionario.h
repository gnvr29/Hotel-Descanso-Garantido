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

        //Getters
        string getCargo();
        float getSalary();
        
        //Metodos da classe
        void armazenaDadosEmArquivo();
};

#endif