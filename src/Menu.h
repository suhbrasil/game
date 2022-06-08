/*
    Vídeo base para o menu: https://www.youtube.com/watch?v=bOG8667yePY&t=602s
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> // ofstream e ifstream
#include <string.h>
using namespace std;
using namespace sf;

#include "Ente.h"

#define max_texto 5

class Menu : public Ente
{
private:
    RenderWindow* janela;
    int selecionado;
    // Texto menu
    Font fonte;
    Text texto[max_texto];
public:
    Menu();
    ~Menu();

    void desenharMenu();
    void MoverCima();
    void MoverBaixo();
    int pressionado();
    void executar();
};
