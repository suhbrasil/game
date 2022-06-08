#pragma once

#include "Jogador.h"

using namespace personagens;

namespace fases {
    class FaseDois {

    private:
        Event event;

        // Tela
        RenderWindow* janela;
        Sprite fundoTela;
        Texture fundoTelaTex;

        // Jogador
        Jogador* jogador;
    public:
        FaseDois(Jogador* j);
        ~FaseDois();

        // Jogador
        void atualizarJogador();
        void atualizarRenderJogador();
        void atualizarColisao();
        void render(RenderWindow& janela);

        void executar();
    };

}