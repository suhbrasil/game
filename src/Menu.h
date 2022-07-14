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

    RenderWindow gameOver;

    Sprite fundoTela;
    Texture fundoTelaTex;

    // Texto menu
    Font fonte;
    Text texto[max_texto];

    // Texto game over
    Font fonteGameOver;
    Text textoGameOver;
public:
    Menu();
    ~Menu();
    void inicializarFundoTela();
    void inicializarTextoMenu();
    void inicializarTextoGameOver();
    void MoverCima();
    void MoverBaixo();
    int pressionado();
    void desenhar(RenderWindow& janela);
    void desenharGameOver();
    void executar() {}
};
