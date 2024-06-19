#include "../Header-files/Funcionario.h"

using namespace std;

Funcionario::Funcionario(string name, string phone, string cargo, float salario){
    this->name = name;
    this->phone = phone;
    this->cargo = cargo;
    this->salary = salario;
}

void Funcionario::armazenaDadosEmArquivo(string dados){
    fstream funcionarioFile("../Binary-files/funcionarios.bin", ios::in | ios::binary);

    if(!funcionarioFile){
        cerr << "Houve um erro ao abrir o arquivo de funcionarios" << endl;
        return;
    }
    size_t dadosLen = dados.size();
    funcionarioFile.write(reinterpret_cast<char*>(&dados), sizeof(dadosLen));
    funcionarioFile.write(dados.c_str(), dadosLen);

    funcionarioFile.close();
}