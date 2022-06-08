#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
using namespace sf;
using namespace std;

namespace gerenciadores {
    class GerenciadorGrafico
    {
    private:
        RenderWindow janela;
    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();

        // Fundo tela jogo
        void inicializarJanela();
        RenderWindow& getJanela();

        // Inicializar Ente
        void desenhar(RectangleShape* background, Texture* text);
    };
}
