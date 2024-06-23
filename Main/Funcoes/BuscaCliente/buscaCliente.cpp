#include "buscaCliente.h"

using namespace std;

string buscaCliente(int code, const string& nome) {

       /*
    Funcao que recebe o codigo ou o nome de um cliente, procura-o no arquivo clientes.txt,
    e apresenta todas as informações do cliente.
    Entrada: int (codigo do cliente) - string (nome do cliente)
    Saida: string (informações do cliente)
    */

    string codigoCliente = to_string(code);
    string nomeCliente = nome;


    //Abre arquivo de cliente para leitura
    ifstream clientesFile("../../data-files/clientes.txt");

    if(!clientesFile){
        cerr << "Houve um erro ao abrir o arquivo de clientes" << endl;
        return "";
    }

    string line;
    string clienteDados = "";

    while(getline(clientesFile, line)) {
        if(line.find(codigoCliente) != string::npos || line.find(nomeCliente) != string::npos){
            clienteDados = line;
            break;
        }
    }

    clientesFile.close();

     if(clienteDados == ""){
        cerr << "Erro: Cliente nao encontrado" << endl;
        return 0;
    }

    //Extrai todas as informacoes da linha
    stringstream ssCliente(line);
    string codigo, name, phone, endereco, pontosDeFidelidade;
    getline(ssCliente, codigo, ',');
    getline(ssCliente, name, ',');
    getline(ssCliente, phone, ',');
    getline(ssCliente, endereco, ',');
    getline(ssCliente, pontosDeFidelidade, ';');

    //Remove espaco em branco no comeco de cada string e salva a string com os dados necessarios
    name = name.substr(1);
    phone = phone.substr(1);
    endereco = endereco.substr(1);
    pontosDeFidelidade = pontosDeFidelidade.substr(1);

    // Exibe a string resultado com os dados do cliente
    string resultado = "Nome: " + name + "\nTelefone: " + phone + "\nEndereço: " + endereco + "\nPontos de Fidelidade: " + pontosDeFidelidade;

    return resultado;

}