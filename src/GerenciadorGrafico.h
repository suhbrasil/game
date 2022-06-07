#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
using namespace sf;
using namespace std;

#include "Ente.h"

namespace gerenciadores {
    class GerenciadorGrafico
    {
    private:
        RenderWindow janela;
        Texture* textura;
    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();

        // Fundo tela jogo
        void inicializarJanela();
        RenderWindow& getJanela();

        // Textura
        void setTextura(Texture* text);
        Texture* getTextura();

        // Background
        void inicializarBackground(RectangleShape* background, Texture* text);
    };
}
