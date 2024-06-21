#include "../Header-files/Funcionario.h"

using namespace std;

Funcionario::Funcionario(string name, string phone, string cargo, float salario){
    this->name = name;
    this->phone = phone;
    this->cargo = cargo;
    this->salary = salario;

    if(!pessoaExiste(to_string(this->code))){
        string dados = criaStringDeDados();
        armazenaDadosEmArquivo(dados);
    } else
        cerr << "Erro: Usuario ja existe";
}

string Funcionario::criaStringDeDados(){
    /*
    Metodo para criar a string que sera armazenada no arquivo contendo todas as informacoes do usuario
    Entrada: void
    Saida: string (dados)
    */
    string dados = 
    to_string(this->code) + ", " +
    this->name + ", " +
    this->phone + ", " +
    this->cargo + ", " +
    to_string(this->salary) + ";\n";
}

bool Funcionario::pessoaExiste(string identificador){
    /*
    Metodo para verificar se o funcionario ja foi registrado
    Retorna true se o funcionario existir, ou se houver um problema ao abrir o arquivo
    Retorna false se o funcionario nao existir
    Entrada: string (codigo ou nome)
    Saida: bool
    */
    ifstream funcionariosFile("../data-files/funcionarios.txt");

    if(!funcionariosFile){
        cerr << "Houve um erro ao abrir o arquivo de funcionarios" << endl;
        return true;
    }

    string line;
    while(getline(funcionariosFile, line)){
        if(line.find(identificador) != string::npos){
            funcionariosFile.close();
            return true;
        }
    }

    funcionariosFile.close();
    return false;
}

int Funcionario::armazenaDadosEmArquivo(string dados){
    /*
    Metodo para armazenar dados do funcionario no arquivo de funcionarios
    Retorna -1 se houver um problema ao abrir o arquivo e 0 se nao houver erro nenhum
    Entrada: String (dados)
    Saida: int (codigo de erro)
    */

    ofstream funcionarioFile("../data-files/funcionarios.txt");

    if(!funcionarioFile){
        cerr << "Houve um erro ao abrir o arquivo de funcionarios" << endl;
        return -1;
    }

    funcionarioFile << dados;
    funcionarioFile.close();
}