#include "../Header-files/Pessoa.h"

using namespace std;

int Pessoa::contador = 0;

Pessoa::Pessoa(){
    code = ++contador;
}

int Pessoa::getCode(){
    return this->code;
}

string Pessoa::getName(){
    return this->name;
}

string Pessoa::getPhone(){
    return this->phone;
}
