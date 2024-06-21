#include "cadastraFuncionario.h"

void cadastraFuncionario() {
    string nome, telefone, cargo;
    float salario;

    cout << "Digite o nome do funcionario:" << endl;
    getline(cin, nome);

    cout << "Digite o numero de telefone do funcionario:" << endl;
    getline(cin, telefone);

    cout << "Digite o cargo do funcionario:" << endl;
    getline(cin, cargo);

    cout << "Digite o salario do funcionario: " << endl;
    cin >> salario;

    //Armazenamento em arquivo e verificacao de existencia do funcionario sao feitas dentro da classe
    Funcionario funcioarioAtual(nome, telefone, cargo, salario);
}