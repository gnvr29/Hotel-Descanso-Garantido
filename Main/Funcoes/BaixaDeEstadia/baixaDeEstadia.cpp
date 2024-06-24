#include "baixaDeEstadia.h"

using namespace std;

int baixaDeEstadia(){
    /*
    Funcao que recebe o codigo de uma estadia, procura-a no arquivo estadias.txt,
    pega o numero do quarto e altera seu status, e retorna o valor a ser pago
    Retorna 1 se houver erro ao abrir um arquivo ou se o quarto ou estadia nao existir
    Retorna 0 se tudo ocorrer como planejado
    Entrada: void
    Saida: void
    */

    string codigoEstadia;
    cout << "Digite o codigo da estadia:" << endl;
    getline(cin, codigoEstadia);

    //Abre arquivo de estadia para leitura
    ifstream estadiasFile("../../data-files/estadias.txt");

    if(!estadiasFile){
        cerr << "Houve um erro ao abrir o arquivo de estadia" << endl;
        return 1;
    }
    
    //Procura estadia com determinado codigo e armazena a linha contendo sua informacoes
    string line;
    string estadiaData = "";
    while(getline(estadiasFile, line)){
        if(line.find(codigoEstadia) != string::npos){
            estadiaData = line;
            break;
        }
    }

    if(estadiaData == ""){
        cerr << "Erro: estadia nao encontrada" << endl;
        return 1;
    }

    //Extrai todas informacoes da linha
    stringstream ssEstadia(line);
    string temp, diarias, clientCode, quartoNum;
    getline(ssEstadia, temp, ',');
    getline(ssEstadia, temp, ',');
    getline(ssEstadia, temp, ',');
    getline(ssEstadia, diarias, ',');
    getline(ssEstadia, clientCode, ',');
    getline(ssEstadia, quartoNum, ';');

    //Remove espaco em branco no comeco de cada string e salva a string com os dados necessarios
    diarias = diarias.substr(1);
    clientCode = clientCode.substr(1);
    quartoNum = quartoNum.substr(1);

    estadiasFile.close();


    //Abre o arquivo de quartos
    ifstream quartosFile("../../data-files/quartos.txt");
    
    //Procura o quarto baseado no seu numero e armazena todas as linhas lidas num vetor para
    //poder editar o status do arquivo

    string quartoLine;
    string quartoData = "";
    vector<string> quartoAllLines;

    while(getline(estadiasFile, quartoLine)){
        if(line.find(quartoNum) != string::npos){
            quartoData = quartoLine;
        } else {
            quartoAllLines.push_back(quartoLine);
        }
    }
    quartosFile.close();

    if(quartoData == ""){
        cerr << "Erro: quarto nao registrado" << endl;
        return 1;
    }

    //Extrai todas as informacoes do quarto
    stringstream ssQuarto(quartoLine);
    string temp, hospedes, valorDiaria;
    getline(ssQuarto, temp, ',');
    getline(ssQuarto, hospedes, ',');
    getline(ssQuarto, valorDiaria, ',');
    
    hospedes = hospedes.substr(1);
    valorDiaria = valorDiaria.substr(1);

    //Cria a string com status desocupado
    string quartoDesocupado = 
        quartoNum + ", " +
        hospedes + ", " +
        valorDiaria + ", " +
        "desocupado;\n";

    //Insere a string com status desocupado no vetor, para sobrescrever o arquivo com as linhas armazenadas logo em seguida
    quartoAllLines.push_back(quartoDesocupado);

    //Altera o status do quarto para desocupado ao sobrescrever 
    ofstream quartosFileEditar("../../data-files/quartos.txt");

    if(!quartosFileEditar){
        cerr << "Houve um erro ao abrir o arquivo de quartos para editar o status do quarto" << endl;
        return 1;
    }

    for(string quarto : quartoAllLines){
        quartosFileEditar << quarto;
    }
    quartosFileEditar.close();

    //Calcula o valor a ser pago
    int valorPago = stoi(diarias) * stoi(valorDiaria);

    cout << "A baixa na estadia foi realizada com sucesso!" << endl << "O valor a ser pago sera: R$" << valorPago << ",00" << endl;
    return 0;
}