#include "menu.h"

using namespace std;

void menu(){
    bool exit = false;
    cout << "Bem vindo(a) ao Hotel Descanso Garantido!!" << endl << "O que deseja fazer?" << endl;
    while(!exit){
        cout << "1) Cadastrar um cliente" << endl << "2) Cadastrar um funcionario" << endl << "3) Cadastrar uma estadia" << endl << "4) Pesquisar um funcionario" << endl << "5) Pesquisar um cliente" << endl << "6) Sair" << endl;
        int input = 0;
        switch(input) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                cout << "Obrigado pela interacao, volte sempre...";
                exit = true;
                break;
            default:
                cout << "Entrada invalida - Tente novamente" << endl;
                break;
        }

    }
}