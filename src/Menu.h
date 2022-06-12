/*
    Vídeo base para o menu: https://www.youtube.com/watch?v=bOG8667yePY&t=602s
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> // ofstream e ifstream
#include <string.h>
#include "Ente.h"
using namespace std;
using namespace sf;

#define max_texto 6

class Menu : public Ente
{
private:
    int selecionado;
    // Texto menu
    Font fonte;
    Text texto[max_texto];
public:
    Menu(float largura = 0.0f, float altura = 0.0f);
    ~Menu();

    void desenhar(RenderWindow& janela);
    void MoverCima();
    void MoverBaixo();
    int pressionado();
    void executar() {}
};
