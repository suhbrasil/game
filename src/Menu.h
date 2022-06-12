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

    Sprite fundoTela;
    Texture fundoTelaTex;

    RenderWindow j;

    // Texto menu
    Font fonte;
    Text texto[max_texto];

    // Texto game over
    Font fonteGameOver;
    Text textoGameOver;
public:
    Menu(float largura = 0.0f, float altura = 0.0f);
    ~Menu();
    void inicializarFundoTela();
    void inicializarTextoMenu();
    void inicializarTextoGameOver(int perdeu);
    void MoverCima();
    void MoverBaixo();
    int pressionado();
    void desenhar(RenderWindow& janela);
    void desenharGameOver(RenderWindow& janela, int perdeu);
    void executar() {}
};
