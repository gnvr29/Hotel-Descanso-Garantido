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
        time_t entryDate;
        time_t exitDate;
        int quantDiarias;
        int codeCliente;
        Quarto* quarto;
        int numero;

    public:
    Estadia(time_t entryDate, time_t exitDate, int codigoCliente, Quarto* quarto);

    static Estadia* cadastrarEstadia(int codigoCliente, int quantidadeHospedes, time_t dataEntrada, time_t dataSaida, std::vector<Quarto>& quartosDisponiveis);
    void printEstadiaDetails() const;

};









#endif 