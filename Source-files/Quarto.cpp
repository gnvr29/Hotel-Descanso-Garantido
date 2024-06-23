#include "../Header-files/Quarto.h"

using namespace std;

int Quarto::contador = 0;

Quarto::Quarto(int hospedes) {
    this->numero = ++contador;
    this->hospedes = hospedes;
    this->diaria = valorDiaria();
    this->status = "desocupado";

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

int Quarto::valorDiaria() {
    diaria = 300 + (150 * hospedes);
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
    Funcao para armazenar os dados do quarto no arquivo
    Retorna 1 se houver problema ao abrir o arquivo
    Retorna 0 se os dados forem armazenados com sucesso
    Entrada: string 
    Saida: int
    */
    ofstream quartoFile("../data-files/quartos.txt", ios::app);

    if(!quartoFile) {
        cerr << "Houve um erro ao abrir o arquivo de quartos";
        return 1;
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