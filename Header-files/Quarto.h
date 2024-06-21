#ifndef QUARTO_H
#define QUARTO_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Quarto {
    private:
        int numero;
        int hospedes;
        float diaria;
        bool status;
    
    //Getters
    public:
        int getNumero();
        int getHospedes();
        double getDiaria();
        bool getStatus();
        void ocupado();
        void liberado();

};

#endif