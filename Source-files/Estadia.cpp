#include "../Header-files/Estadia.h"

using namespace std;

#include <Estadia.h>

int Estadia::contador = 1;

Estadia::Estadia(time_t entryDate, time_t exitDate, int codeCliente, Quarto* quarto)
    : entryDate(entryDate), exitDate(exitDate), codeCliente(codeCliente), quarto(quarto) {

    // Calcula a quantidade de diárias
    quantDiarias = (entryDate, exitDate);

    // Define o código da estadia
    codeEstadia = contador++;
}