#ifndef QUARTO_H
#define QUARTO_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Quarto {
    private:
        static int contador;
        int numero;
        int hospedes;
        float diaria;
        string status;
    
    public:
      Quarto();
      float valorDiaria();
      Quarto(int hospedes, string status);
      bool quartoExiste(string identificador);
      virtual string criaStringDeDados();
      virtual int armazenaDadosEmArquivo(string dados);

};

#endif