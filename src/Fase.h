#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Jogador.h"

using namespace sf;
using namespace std;
using namespace personagens;

namespace fases{

    class Fase {

    private:
        Event event;

        // Tela
        RenderWindow* janela;
        Sprite fundoTela;
        Texture fundoTelaTex;

        // Jogador
        Jogador* jogador;
    public:
        Fase(Jogador* j);
        ~Fase();

        // Jogador
        void atualizarJogador();
        void atualizarRenderJogador();
        void atualizarColisao();
        void render(RenderWindow& janela);

        void executar();
    };
}
