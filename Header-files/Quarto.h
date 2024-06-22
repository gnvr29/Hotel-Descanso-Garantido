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
      Quarto(int hospedes, int diaria, bool status);
      bool quartoExiste(string identificador);
      virtual string criaStringDeDados();
      virtual int armazenaDadosEmArquivo(string dados);

};

#endif