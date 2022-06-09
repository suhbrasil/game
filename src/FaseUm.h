#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Obstaculo.h"
#include "Fase.h"
using namespace obstaculos;
using namespace entidades;
using namespace personagens;
using namespace sf;

namespace fases
{
    class FaseUm : public Fase
    {

    private:
        Event event;

        // Tela
        RenderWindow janela;
        Sprite fundoTela;
        Texture fundoTelaTex;

        // Jogador
        Jogador* jogador;

        // Obstaculo
        Obstaculo* obstaculo;
    public:
        FaseUm(Jogador *j);
        ~FaseUm();

        // Tela
        void inicializarJanela();
        const RenderWindow& getJanela() const;
        void inicializarFundoTela();
        void renderFundoTela();

        // Obstaculos
        void inicializarObstaculo();

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
