#include "buscaFuncionario.h"

using namespace std;

int buscaFuncionario() {
    /*
    Funcao que recebe o codigo ou o nome de um Funcionario, procura-o no arquivo Funcionarios.txt,
    e apresenta todas as informações do Funcionario.
    Retorna 1 se houver algum problema ao abrir o arquivo, ou se o funcionario nao existir
    Entrada: int (codigo do Funcionario) - string (nome do Funcionario)
    Saida: string (informações do Funcionario)
    */

    string identificador;
    cout << "Digite o codigo ou nome do funcionario:" << endl;
    getline(cin, identificador);

    //Abre arquivo de Funcionario para leitura
    ifstream FuncionariosFile("../../data-files/Funcionarios.txt");

    if(!FuncionariosFile){
        cerr << "Houve um erro ao abrir o arquivo de Funcionarios" << endl;
        return 1;
    }

    string line;
    string FuncionarioDados = "";

    while(getline(FuncionariosFile, line)) {
        if(line.find(identificador) != string::npos){
            FuncionarioDados = line;
            break;
        }
    }
    FuncionariosFile.close();

    if(FuncionarioDados == ""){
        cerr << "Erro: Funcionario nao encontrado" << endl;
        return 1;
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
    cout << resultado << endl;
    return 0;
}