#ifndef ESTADIA_H
#define ESTADIA_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <vector>
#include <chrono>
#include <iomanip>

#include "Quarto.h"

using namespace std;

class Estadia {
    private:
        static int contador;
        int estadiaCode;
        int hospedes;
        string checkInDate;
        string checkOutDate;
        int diarias;
        int clientCode;
        int quartoNum;

    int calculaDiarias();
    string criaStringDeDados();
    bool clienteExiste(int clientCode);
    int encontraQuarto();
    int armazenaEmArquivoEalteraFidelidade(string dados);

    public:
    Estadia(int clientCode, int hospedes, string checkInDate, string checkOutDate);

};

#endif 