#include "../Header-files/Pessoa.h"

using namespace std;

int Pessoa::contador = 0;

Pessoa::Pessoa(){
    code = ++contador;
}

