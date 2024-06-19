#include "cadastraCliente.h"

void cadastraCliente() {
    string nome, telefone, endereco;

    cout << "Digite o nome do cliente:" << endl;
    getline(cin, nome);

    cout << "Digite o numero de telefone do cliente:" << endl;
    getline(cin, telefone);

    cout << "Digite o endereco do cliente:" << endl;
    getline(cin, endereco);

    Cliente clienteAtual(nome, telefone, endereco);
}