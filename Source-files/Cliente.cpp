#include "../Header-files/Cliente.h"

using namespace std;

Cliente::Cliente(string name, string phone, string endereco) {
    this->name = name;
    this->phone = phone;
    this->endereco = endereco;
    this->pontosDeFidelidade = definePontosDeFidelidade();
    
    string clienteStr = criaStringDeDados();
    armazenaDadosEmArquivo(clienteStr);
}

//Getters
string Cliente::getEndereco(){
    return this->endereco;
}

int Cliente::getPontosDeFidelidade(){
    return this->pontosDeFidelidade;
}

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
        + to_string(this->pontosDeFidelidade) + ";";
    
    return dados;
}

int Cliente::pesquisaDiarias(){
    /*
    Funcao para pesquisar, no arquivo de estadias, todas as estadias do usuario e calcular no numero de diarias (usado no calculo de pontos de fidelidade)
    Retorna -1 se houver um problema ao abrir o arquivo
    Entrada: void
    Saida: int (numero de diarias registradas no nome do usuario)
    */

    ifstream estadiaFile("../Binary-files/estadias.bin", ios::binary);

    if(!estadiaFile){
        cerr << "Houve um erro ao abrir o arquivo de estadias" << endl;
        return -1;
    }


    int diarias;
    estadiaFile.close();

    return diarias;
}

int Cliente::definePontosDeFidelidade(){
    /*
    Funcao que realiza o calculo de pontos de fidelidade do usuario, baseado no valor retornado por pesquisaDiarias()
    Entrada: void
    Saida: int (pontosDeFidelidade)
    */
    int numeroDeDiarias = pesquisaDiarias();
    int pontosDeFidelidade = 10 * numeroDeDiarias;
    
    return pontosDeFidelidade;
}

void Cliente::armazenaDadosEmArquivo(string dados){
    /*
    Funcao para armazenar um dada string no arquivo binario de clientes
    Entrada: string 
    Saida: void
    */
    fstream clienteFile("../Binary-files/clientes.bin", ios::out | ios::binary);

    if(!clienteFile) {
        cerr << "Houve um erro ao abrir o arquivo";
        return;
    }
    
    size_t dadosLen = dados.size(); //Armazena o tamanho em bytes da string
    clienteFile.write(reinterpret_cast<char*>(&dados), sizeof(dadosLen)); //Reserva o espaco no arquivo
    clienteFile.write(dados.c_str(), dadosLen); //Escreve o conteudo no espaco reservado. c_str() converte a string para um array de caracteres, como em C
    clienteFile.close();
}