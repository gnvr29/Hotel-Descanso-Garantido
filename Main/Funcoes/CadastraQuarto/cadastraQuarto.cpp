#include "cadastraQuarto.h"

void cadastraQuarto() {
    int  hospedes;

    cout << "Digite a quantidade de hospedes que irão se hospedar no quarto:" << endl;
    cin >> hospedes;

    //Armazenamento em arquivo e verificacao de existencia do usuario sao feitas dentro da classe
    Quarto quartoAtual(int hospedes);
}