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
        View camera;
    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();

        // Fundo tela jogo
        void inicializarJanela();
        RenderWindow* getJanela();
        View* getView();
        void centralizar(const Vector2f centro);
        void resetCamera();
    };
}
