#ifndef ESTADIA_H
#define ESTADIA_H

#include <iostream>
#include <fstream>
#include <ctime>

#include "Quarto.h"

using namespace std;

class Estadia {
    private:
        static int contador;
        int codeEstadia;
        string checkInDate;
        string checkOutDate;
        int quantDiarias;
        int codeCliente;
        int quartoNum;

    public:
    Estadia();


};

#endif 