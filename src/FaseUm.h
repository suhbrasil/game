#pragma once
#include "Jogador.h"
#include <SFML/Graphics.hpp>
using namespace personagens;
using namespace sf;

namespace fases
{
    class FaseUm
    {

    private:
        Event event;

        // Tela
        RenderWindow janela;
        Sprite fundoTela;
        Texture fundoTelaTex;

        // Jogador
        Jogador *jogador;
    public:
        FaseUm(Jogador *j);
        ~FaseUm();

        // Tela
        void inicializarJanela();
        const RenderWindow& getJanela() const;
        void inicializarFundoTela();
        void renderFundoTela();

        // Jogador
        void inicializarJogador(Jogador* j);
        void atualizarJogador();
        void atualizar();
        void atualizarRenderJogador();
        void atualizarColisao();
        void render();

        void executar();
    };
}
