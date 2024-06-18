#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
using namespace std;

class Cliente: public Pessoa {
    private:
        string endereco;
        int pontosDeFidelidade;
};

#endif