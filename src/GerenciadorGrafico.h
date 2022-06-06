#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

namespace gerenciadores {
    class GerenciadorGrafico
    {
    private:
        RenderWindow janela;

        // Fundo tela
        Sprite fundoTela;
        Texture fundoTelaTex;
    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();

        // Fundo tela
        void inicializarJanela();
        RenderWindow& getJanela();
        void inicializarFundoTela();
        void renderFundoTela();
    };
}
