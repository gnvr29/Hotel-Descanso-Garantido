#include "../Header-files/Estadia.h"
#include "../Main/Funcoes/CalculaPontosDeFidelidade/calculaPontosDeFidelidade.h"

using namespace std;

int Estadia::contador = 0;

Estadia::Estadia(int clientCode, int hospedes, string checkInDate, string checkOutDate){
    this->estadiaCode = ++contador;
    this->hospedes = hospedes;
    this->checkInDate = checkInDate;
    this->checkOutDate = checkOutDate;
    this->diarias = calculaDiarias();
    this->clientCode = clientCode;
    this->quartoNum = encontraQuarto();

    string dados = criaStringDeDados();
    armazenaEmArquivoEalteraFidelidade(dados);
}

string Estadia::criaStringDeDados(){
    string stringDeDados = 
        to_string(this->estadiaCode) + ", " +
        this->checkInDate + ", " +
        this->checkOutDate + ", " +
        to_string(this->diarias) + ", " +
        to_string(this->clientCode) + ", " +
        to_string(this->quartoNum) + ";\n";
    
    return stringDeDados;
}

int Estadia::calculaDiarias(){
    /*
    Metodo utilizado para calcular o numero de diarias, dados as strings de checkIn e checkOut 
    no formato YYYY-MM-DD. Retorna o numero de diarias.
    Retorna -1 se houver um erro ao converter as strings de data para datas
    Entrada: void
    Saida: int (numero de diarias)
    */

    tm checkIn = {};
    tm checkOut = {};

    istringstream ssCheckIn(checkInDate);
    istringstream ssCheckOut(checkOutDate);

    if (!(ssCheckIn >> get_time(&checkIn, "%Y-%m-%d"))) {
        cerr << "Erro: a data de checkin esta no formato incorreto" << endl;
        return -1;
    }

    if (!(ssCheckOut >> get_time(&checkOut, "%Y-%m-%d"))) {
        cerr << "Erro: a data de checkout esta no formato incorreto" << endl;
        return -1;
    }

    //Ajusta os valores para que os valores sejam inseridos da maneira correta: janeiro = 0, fevereiro = 1, etc.
    checkIn.tm_year -= 1900;
    checkIn.tm_mon -= 1;
    checkOut.tm_year -= 1900;
    checkOut.tm_mon -= 1;

    auto checkInEmHoras = chrono::system_clock::from_time_t(mktime(&checkIn));
    auto checkOutEmHoras = chrono::system_clock::from_time_t(mktime(&checkOut));

    auto diasEmHoras = chrono::duration_cast<chrono::hours>(checkOutEmHoras - checkInEmHoras).count();
    return diasEmHoras / 24;
}

int Estadia::encontraQuarto(){
    /*
    Metodo que procura por um quarto desocupado e com o numero de hospedes
    correspondente ao solicitado pelo cliente. Retorna o numero do quarto selecionado e
    altera o status do quarto no arquivo de quartos para ocupado
    Retorna 0 se houver um problema ao abrir o arquivo, ou se nao houver um quarto disponivel
    Entrada: void
    Saida: int (numero do quarto)
    */

    ifstream quartosFile("../data-files/quartos.txt");

    if(!quartosFile){
        cerr << "Houve um problema ao abrir o arquivo de quartos";
        return 0;
    }

    int quartosEncontrados = 0;
    string numeroDoQuarto = "";
    vector<string> quartosVetor;
    string line;

    while(getline(quartosFile, line)){
        string quartoNumLinha, hospedesLinha, valorQuartoLinha, statusLinha;
        stringstream ss(line);
        getline(ss, quartoNumLinha, ',');
        getline(ss, hospedesLinha, ',');
        getline(ss, valorQuartoLinha, ',');
        getline(ss, statusLinha, ';');

        hospedesLinha = hospedesLinha.substr(1);
        statusLinha = statusLinha.substr(1);
        valorQuartoLinha = valorQuartoLinha.substr(1);

        if(this->hospedes == stoi(hospedesLinha) && statusLinha == "desocupado" && quartosEncontrados != 1){
            quartosEncontrados++;
            numeroDoQuarto = quartoNumLinha;
            string templateStr = 
                quartoNumLinha + ", " +
                hospedesLinha + ", " +
                valorQuartoLinha + ", " +
                "ocupado;\n";
            quartosVetor.push_back(templateStr);
        } else {
            string templateStr = 
                quartoNumLinha + ", " +
                hospedesLinha + ", " +
                valorQuartoLinha + ", " +
                statusLinha + ";\n";
            quartosVetor.push_back(templateStr);
        }
    }

    if(numeroDoQuarto.empty()){
        cout << "Nao ha nenhum quarto disponivel com as especificacoes disponiveis" << endl;
        return 0;
    }

    return stoi(numeroDoQuarto);
}

bool Estadia::clienteExiste(int clientCode){
    /*
    Metodo para verificar se o cliente existe
    Retorna true se o usuario ja for cadastrado ou se houver algum problema ao abrir o arquivo
    Retorna false se ele nao for cadastrado
    Entrada: string (codigo ou nome)
    Saida: bool
    */
    ifstream arquivoCliente("../data-files/clientes.txt");

    if(!arquivoCliente){
        cerr << "Houve um problema ao abrir o arquivo de clientes para verificacao" << endl;
        return true;
    }

    string line;
    while(getline(arquivoCliente, line)){
        if(line.find(clientCode) != string::npos){
            arquivoCliente.close();
            return true;
        }
    }

    arquivoCliente.close(); 
    return false;
}

int Estadia::armazenaEmArquivoEalteraFidelidade(string dados){
    /*
    Funcao para armazenar os dados da estadia no arquivo e alterar os 
    Retorna 1 se houver problema ao abrir o arquivo, se o cliente nao existir ou se houver problema com as datas
    Retorna 0 se os dados forem armazenados com sucesso.
    Entrada: string 
    Saida: int
    */
    ofstream clienteFile("../data-files/clientes.txt", ios::app);

    if(!clienteFile) {
        cerr << "Houve um erro ao abrir o arquivo de clientes";
        return 1;
    }

    if(!clienteExiste(this->clientCode)){
        cerr << "Erro: nao foi possivel armazenar os dados da estadia - cliente nao existe" << endl;
        return 1;
    }

    if(this->diarias == -1){
        return 1;
    }

    clienteFile << dados;
    clienteFile.close();

    calculaPontosDeFidelidade(to_string(this->clientCode));

    return 0;
}