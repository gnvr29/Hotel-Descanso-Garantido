#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"
using namespace std;

class Funcionario: public Pessoa {
    private:
        string cargo;
        float salary;
};

#endif