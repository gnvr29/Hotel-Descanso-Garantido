#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"
using namespace std;

class Funcionario: public Pessoa {
    private:
        string cargo;
        float salary;
    
    public:
        Funcionario(int code, string name, string phone, string cargo, float salary);

        //Getters
        int getCode();
        string getName();
        string getPhone();
        string getCargo();
        float getSalary();
        
        //Metodos da classe
        void armazenaDadosEmArquivo();
};

#endif