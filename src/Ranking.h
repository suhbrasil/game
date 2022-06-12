#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include <fstream> // ofstream e ifstream
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

#define max_ranking 100

class Ranking
{
private:
    string nome1;
    string nome2;
    int pontos;
    // verificar se tem algum nome salvo
    int salvo;

    // Texto ranking
    Font fonteRanking;
    Text textoRanking[max_ranking];
    int maxRanking;
public:
    Ranking();
    ~Ranking();

    void salvarPontos1(int p);
    void salvarPontos2(int p1, int p2);
    void salvarNome1();
    void salvarNome2();
    void desenhar(RenderWindow& janela);
};
