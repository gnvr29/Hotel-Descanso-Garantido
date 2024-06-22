#include "../Header-files/Quarto.h"

using namespace std;

Quarto::Quarto(){
    numero = ++contador;
}

float Quarto::valorDiaria() {
    diaria = 300 + (150 * hospedes);
}

Quarto::Quarto(int hospedes, string status) {
    this->hospedes = hospedes;
    this->status = status;

       if(!quartoExiste(to_string(numero))){
        string quartoStr = criaStringDeDados();
        armazenaDadosEmArquivo(quartoStr);
    } else 
        cerr << "Erro: Quarto já existe - Tente novamente" << endl;
}

string Quarto::criaStringDeDados(){
    string dados = 
        to_string(this->numero) + ", "
        + to_string(this->hospedes) + ", "
        + to_string(this->diaria) + ", "
        + (this->status) + ";\n";       
    
    return dados;
}

bool Quarto::quartoExiste(string identificador){

    ifstream arquivoQuarto("../data-files/quartos.txt");

    if(!arquivoQuarto){
        cerr << "Houve um problema ao abrir o arquivo de quartos" << endl;
        return true;
    }

    string line;
    while(getline(arquivoQuarto, line)){
        if(line.find(identificador) != string::npos){
            arquivoQuarto.close(); 
            return true;
        }
    }
    arquivoQuarto.close();  
    return false;
}

int Quarto::armazenaDadosEmArquivo(string dados){
    /*
    Funcao para armazenar os dados do cliente no arquivo binario
    Retorna -1 se houver problema ao abrir o arquivo
    Retorna 0 se os dados forem armazenados com sucesso
    Entrada: string 
    Saida: int
    */
    ofstream quartoFile("../data-files/quartos.txt");

    if(!quartoFile) {
        cerr << "Houve um erro ao abrir o arquivo de quartos";
        return -1;
    }

    quartoFile << dados;
    quartoFile.close();

    return 0;
}



















/*
double Quarto::getDiaria() {
    diaria = 300 + (150 * hospedes);
}

int Quarto::getNumero(){
    return this->numero;
}

int Quarto::getHospedes(){
    return this->hospedes;
}

string Quarto::getStatus(){
    return this->status;
}

void Quarto::ocupado() { 
    status = false; 
}

void Quarto::liberado() { 
    status = true; 
}
*/