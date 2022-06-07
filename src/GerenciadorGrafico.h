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

        // Fundo tela
        Sprite fundoTela;
        Texture fundoTelaTex;

        // Pilha
        stack<Ente*> pilha;
    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();

        // Fundo tela jogo
        void inicializarJanela();
        RenderWindow& getJanela();
        void inicializarFundoTela();
        void renderFundoTela();

        // Pilha
        void inserir(Ente* elem);
        Ente* recuperar();
    };
}
