#include "buscaFuncionario.h"

using namespace std;

string buscaFuncionario(int code, const string& nome) {

       /*
    Funcao que recebe o codigo ou o nome de um Funcionario, procura-o no arquivo Funcionarios.txt,
    e apresenta todas as informações do Funcionario.
    Entrada: int (codigo do Funcionario) - string (nome do Funcionario)
    Saida: string (informações do Funcionario)
    */

    string codigoFuncionario = to_string(code);
    string nomeFuncionario = nome;


    //Abre arquivo de Funcionario para leitura
    ifstream FuncionariosFile("../../data-files/Funcionarios.txt");

    if(!FuncionariosFile){
        cerr << "Houve um erro ao abrir o arquivo de Funcionarios" << endl;
        return "";
    }

    string line;
    string FuncionarioDados = "";

    while(getline(FuncionariosFile, line)) {
        if(line.find(codigoFuncionario) != string::npos || line.find(nomeFuncionario) != string::npos){
            FuncionarioDados = line;
            break;
        }
    }

     FuncionariosFile.close();

     if(FuncionarioDados == ""){
        cerr << "Erro: Funcionario nao encontrado" << endl;
        return 0;
    }

    //Extrai todas as informacoes da linha
    stringstream ssFuncionario(line);
    string codigo, name, phone, cargo, salary;
    getline(ssFuncionario, codigo, ',');
    getline(ssFuncionario, name, ',');
    getline(ssFuncionario, phone, ',');
    getline(ssFuncionario, cargo, ',');
    getline(ssFuncionario, salary, ';');

    // Remove espaco em branco no comeco de cada string
    name = name.substr(1);
    phone = phone.substr(1);
    cargo = cargo.substr(1);
    salary = salary.substr(1);

    // Exibe a string resultado com os dados do Funcionario
    string resultado = "Nome: " + name + "\nTelefone: " + phone + "\nCargo: " + cargo + "\nSalario: " + salary;

    return resultado;

}