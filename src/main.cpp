#include "Menu.h"

int main()
{
    Menu* menu = new Menu();
    menu->executar();
    delete menu;
    menu = nullptr;

    return 0;
}
