#include "exibeEstadias.h"

using namespace std;

int exibeEstadias(){
    /*
    Funcao para exibir todos os dados de uma determinada estadia. 
    Retorna 1 se houver um rpoblema ao abrir um arquivo ou se a estadia nao existir
    Retorna 0 se tudo ocorrer como planejado.
    Entrada: void
    Saida: void
    */

    string codigoEstadia;
    cout << "Digite o codigo da estadia:" << endl;
    getline(cin, codigoEstadia);

    //Abre arquivo de estadia para leitura
    ifstream estadiasFile("../../../data-files/estadias.txt");

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
    estadiasFile.close();

    if(estadiaData == ""){
        cerr << "Erro: estadia nao encontrada" << endl;
        return 1;
    }

    //Extrai todas informacoes da linha
    stringstream ssEstadia(line);
    string code, checkindate, checkoutdate, diarias, clientCode, quartoNum;
    getline(ssEstadia, code, ',');
    getline(ssEstadia, checkindate, ',');
    getline(ssEstadia, checkoutdate, ',');
    getline(ssEstadia, diarias, ',');
    getline(ssEstadia, clientCode, ',');
    getline(ssEstadia, quartoNum, ';');

    //Remove espaco em branco no comeco de cada string e salva a string com os dados necessarios
    checkindate = checkindate.substr(1);
    checkoutdate = checkoutdate.substr(1);
    diarias = diarias.substr(1);
    clientCode = clientCode.substr(1);
    quartoNum = quartoNum.substr(1);
    
    string estadiaData = "Codigo: " + code + "\nData de check-in: " + checkindate + "\nData de check-out: " + checkoutdate + "\nDiarias: " + diarias + "\nCodigo do cliente: " + clientCode
    + "\nQuarto: " + quartoNum;

    cout << estadiaData << endl;

    return 0;
}