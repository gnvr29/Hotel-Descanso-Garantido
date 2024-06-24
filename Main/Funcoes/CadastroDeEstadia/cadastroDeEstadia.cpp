#include "cadastroDeEstadia.h"

using namespace std;

int cadastraEstadia(){
    int clientCode, hospedes;
    string checkInDate, checkOutDate;
    cout << "Digite o codigo do cliente:" << endl;
    cin >> clientCode;
    cout << "Digite o numero de hospedes:" << endl;
    cin >> hospedes;
    cout << "Digite a data de check-in no formato AA-MM-DD (inclua os hifens e nao utilize espacos):" << endl;
    getline(cin, checkInDate);
    cout << "Digite a data de check-out no formato AA-MM-DD (inclua os hifens e nao utilize espacos):" << endl;
    getline(cin, checkOutDate);

    Estadia novaEstadia(clientCode, hospedes, checkInDate, checkOutDate);
    return 0;
}