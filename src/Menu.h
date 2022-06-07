#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> // ofstream e ifstream
#include <string.h>
using namespace std;
using namespace sf;

#define max_texto 5

class Menu
{
private:
    int selecionado;
    Font fonte;
    Text texto[max_texto];
public:
    Menu(float largura, float altura);
    Menu() {}
    ~Menu();

    void desenhar(RenderWindow& janela);
    void MoverCima();
    void MoverBaixo();
    int pressionado();
    void executar() {}
};
