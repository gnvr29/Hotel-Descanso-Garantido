#include "../Header-files/Cliente.h"

using namespace std;

Cliente::Cliente(string name, string phone, string endereco) {
    this->name = name;
    this->phone = phone;
    this->endereco = endereco;
    this->pontosDeFidelidade = 0;
    
    if(!pessoaExiste(to_string(code))){
        string clienteStr = criaStringDeDados();
        armazenaDadosEmArquivo(clienteStr);
    } else 
        cerr << "Erro: Cliente ja existe - Tente novamente" << endl;
}

//Getters
/*
string Cliente::getEndereco(){
    return this->endereco;
}

int Cliente::getPontosDeFidelidade(){
    return this->pontosDeFidelidade;
}
*/

string Cliente::criaStringDeDados(){
    /*
    Cria a string que sera armazenada no arquivo no formato:
    codigo, nome, telefone, endereco, pontosDeFidelidade;
    Entrada: void
    Saida: String (dados do cliente separados por virgula)
    */
    string dados = 
        to_string(this->code) + ", "
        + this->name + ", "
        + this->phone + ", "
        + this-> endereco + ", "
        + to_string(this->pontosDeFidelidade) + ";\n";
    
    return dados;
}

bool Cliente::pessoaExiste(string identificador){
    /*
    Metodo para verificar se o usuario ja existe (usado ao criar o usuario)
    Retorna true se o usuario ja for cadastrado ou se houver algum problema ao abrir o arquivo
    Retorna false se ele nao for cadastrado
    Entrada: string (codigo ou nome)
    Saida: bool
    */
    ifstream arquivoCliente("../data-files/clientes.txt");

    if(!arquivoCliente){
        cerr << "Houve um problema ao abrir o arquivo de clientes" << endl;
        return true;
    }

    string line;
    while(getline(arquivoCliente, line)){
        if(line.find(identificador) != string::npos){
            arquivoCliente.close();
            return true;
        }
    }

    arquivoCliente.close(); 
    return false;
}

int Cliente::armazenaDadosEmArquivo(string dados){
    /*
    Funcao para armazenar os dados do cliente no arquivo binario
    Retorna -1 se houver problema ao abrir o arquivo
    Retorna 0 se os dados forem armazenados com sucesso
    Entrada: string 
    Saida: int
    */
    ofstream clienteFile("../data-files/clientes.txt", ios::app);

    if(!clienteFile) {
        cerr << "Houve um erro ao abrir o arquivo de clientes";
        return -1;
    }

    clienteFile << dados;
    clienteFile.close();

    return 0;
}

/* FUNCOES DESNECESSARIAS: SERAO IMPLEMENTADAS EM OUTRAS FUNCOES OU CLASSES
int Cliente::pesquisaDiarias(){
    /*
    Metodo para pesquisar, no arquivo de estadias, todas as estadias do usuario e calcular no numero de diarias (usado no calculo de pontos de fidelidade)
    Retorna -1 se houver um problema ao abrir o arquivo
    Entrada: void
    Saida: int (numero de diarias registradas no nome do usuario)
    

    ifstream estadiaFile("../Binary-files/estadias.txt");

    if(!estadiaFile){
        cerr << "Houve um erro ao abrir o arquivo de estadias" << endl;
        return -1;
    }
    int diarias;
    string estadia;
    while(getline(estadiaFile, estadia)){
        if(estadia.find(to_string(this->code)) != string::npos){
            
        }
    }

    estadiaFile.close();
    

    return diarias;
}

int Cliente::definePontosDeFidelidade(){
    /*
    Funcao que realiza o calculo de pontos de fidelidade do usuario, baseado no valor retornado por pesquisaDiarias()
    Entrada: void
    Saida: int (pontosDeFidelidade)
    
    int numeroDeDiarias = pesquisaDiarias();
    int pontosDeFidelidade = 10 * numeroDeDiarias;
    
    return pontosDeFidelidade;
}
*/