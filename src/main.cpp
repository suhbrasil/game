#include "Jogo.h"

int main() {

    // Jogo jogo;
    // jogo.executar();

    Menu* menu = new Menu();
    menu->executar();
    delete menu;
    menu = nullptr;

    return 0;

};
