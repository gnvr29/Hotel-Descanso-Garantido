#include "calculaPontosDeFidelidade.h"

using namespace std;

int calculaPontosDeFidelidade(string clientCode){
    /*
    Procedimento que procura, no arquivo de estadias, todas as estadias de um usuario,
    extraindo o numero de diarias, e alterando os pontos de fidelidade do cliente.
    Retorna 1 caso haja um problema ao abrir um arquivo
    Retorna 0 se nenhum usuario for encontrado
    Entrada: int (codigo do cliente)
    Saida: int (pontos de fidelidadade)
    */

    ifstream estadiasFile("../../../data-files/estadias.txt");

    if(!estadiasFile){
        cerr << "Houve um erro ao abrir o arquivo de estadias" << endl;
        return 0;
    }

    string line;
    vector<string> estadiasDoCliente;

    //Armazena todas as linhas contendo estadias de um certo cliente, dado seu codigo
    while(getline(estadiasFile, line)){
        if(line.find(clientCode) != string::npos){
            estadiasDoCliente.push_back(line);
        }
    }

    estadiasFile.close();

    if(estadiasDoCliente.size() == 0){
        return 1;
    }

    string temp;
    int numDiarias = 0;

    //Extrai o numero de diarias de cada linha e os soma ao total de diarias
    for(string estadia : estadiasDoCliente){
        stringstream ssEstadia(estadia);
        string diarias;
        getline(ssEstadia, temp, ',');
        getline(ssEstadia, temp, ',');
        getline(ssEstadia, temp, ',');
        getline(ssEstadia, diarias, ',');
        diarias = diarias.substr(1);
        numDiarias += stoi(diarias);
    }

    int pontos = 10 * numDiarias;

    ifstream clientesFileRead("../../data-files/clientes.txt");

    if(!clientesFileRead){
        cerr << "Houve um problema ao abrir o artigo de clientes para leitura" << endl;
        return 1;
    }
    
    vector<string> vetorDeClientes;
    string clienteDados;

    string codigo, name, endereco, telefone;
    //Armazena todos os clientes que com codigo diferente do fornecido e extrai as informacoes do cliente procurado
    while(getline(clientesFileRead, clienteDados)){
        if(clienteDados.find(clientCode) == string::npos){
            vetorDeClientes.push_back(clienteDados);
        } else {
            stringstream ss;
            getline(ss, codigo, ',');
            getline(ss, name, ',');
            getline(ss, endereco, ',');
            getline(ss, telefone, ',');
        }
    }
    clientesFileRead.close();

    name = name.substr(1);
    endereco = endereco.substr(1);
    telefone = telefone.substr(1);
    
    //String co os dados do usuario contendo seus pontos de fidelidade
    string strModificada = 
        codigo + ", " +
        name + ", " +
        endereco + ", " +
        telefone + ", " + 
        to_string(pontos) + ";\n";
    
    //Armazena a string modificada no vetor de clientes
    vetorDeClientes.push_back(strModificada);

    ofstream clientesFileWrite("../../data-files/clientes.txt");

    //Sobrescreve todo o arquivo com os clientes e substitui a string de dados do cliente procurado pela string editada, que contem
    //seus pontos de fidelidade atualizados
    for(string cliente : vetorDeClientes){
        clientesFileWrite << cliente;
    }
    clientesFileWrite.close();
}