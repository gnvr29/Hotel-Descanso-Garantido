#include "../Header-files/Quarto.h"

using namespace std;

float Quarto::getDiaria() {
    diaria = 300 + (150 * hospedes);
}

int Quarto::getNumero(){
    return this->numero;
}

int Quarto::getHospedes(){
    return this->hospedes;
}

bool Quarto::getStatus(){
    return this->status;
}