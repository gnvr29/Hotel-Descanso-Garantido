#ifndef QUARTO_H
#define QUARTO_H

#include <iostream>
#include <fstream>

using namespace std;

class Quarto {
    private:
        int numero;
        int hospedes;
        float diaria;
        bool status;
    
    //Getters
    public:
        float getDiaria();
        int getNumero();
        int getHospedes();
        bool getStatus();

};



#endif