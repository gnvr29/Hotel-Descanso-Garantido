#include "cadastraCliente.h"

void cadastraCliente() {
    string nome, telefone, endereco;

    cout << "Digite o nome do cliente:" << endl;
    getline(cin, nome);

    cout << "Digite o numero de telefone do cliente:" << endl;
    getline(cin, telefone);

    cout << "Digite o endereco do cliente:" << endl;
    getline(cin, endereco);

    //Armazenamento em arquivo e verificacao de existencia do usuario sao feitas dentro da classe
    Cliente clienteAtual(nome, telefone, endereco);
}