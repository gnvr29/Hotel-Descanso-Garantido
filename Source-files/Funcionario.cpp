#include "../Header-files/Funcionario.h"

using namespace std;

Funcionario::Funcionario(string name, string phone, string cargo, float salario){
    this->name = name;
    this->phone = phone;
    this->cargo = cargo;
    this->salary = salario;
}

void Funcionario::armazenaDadosEmArquivo(){

}