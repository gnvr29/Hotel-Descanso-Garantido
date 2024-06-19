#include "../Header-files/Cliente.h"

using namespace std;

Cliente::Cliente(string name, string phone, string endereco) {
    this->name = name;
    this->phone = phone;
    this->endereco = endereco;
    this->pontosDeFidelidade = this->definePontosDeFidelidade();
}


int Cliente::definePontosDeFidelidade(){

}

string Cliente::getEndereco(){
    return this->endereco;
}

int Cliente::getPontosDeFidelidade(){
    return this->pontosDeFidelidade;
}

void Cliente::armazenaDadosEmArquivo(){

}