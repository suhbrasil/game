#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include <fstream> // ofstream e ifstream
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

#define max_ranking 100

class Ranking
{
private:
    string nome;
    int pontos;

    // Texto ranking
    Font fonteRanking;
    Text textoRanking[max_ranking];
    int maxRanking;
public:
    Ranking();
    ~Ranking();

    void salvarPontos(int p);
    void salvarNome();
    void desenhar(RenderWindow& janela);
};
