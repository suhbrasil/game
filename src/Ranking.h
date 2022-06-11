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
    string nome;
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

    void salvarPontos(int p);
    void salvarNome();
    void desenhar(RenderWindow& janela);
};
