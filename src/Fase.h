#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Espinho.h"
#include "Galho.h"
#include "Ente.h"
using namespace obstaculos;
using namespace entidades;
using namespace personagens;
using namespace sf;
using namespace lista;
using namespace gerenciadores;

namespace fases
{
    class Fase : public Ente
    {
    protected:
        Event event;
        RenderWindow* janela;
        GerenciadorColisoes gerenciadorColisao;
        GerenciadorGrafico* gerenciadorGrafico;

        Vector2i posMouse;
        Vector2f coordMouse;

        // Texto pause
        Font fonte;
        Text texto;

        Sprite fundoTela;
        Texture fundoTelaTex;
        Jogador* jogador;

    public:
        Fase(Jogador *j, GerenciadorGrafico* gf);
        ~Fase();

        // Tela
        Sprite getImagem();
        void inicializarFundoTela();
        void renderFundoTela();
        Texture getFundoTela();

        // Pausar jogada
        void salvarJogada();
        void pausarJogada();

        // Pontos
        void verPontos();

        // Jogador
        void inicializarJogador(Jogador* j);
        virtual void atualizarRenderObstaculos() = 0;
       virtual void atualizarRenderInimigos() = 0;
        void atualizarJogador();
        void atualizar();
        void atualizarRenderJogador();
        void atualizarColisao();
        void render();
        int gerarAleatoriamente(int maior, int menor);

        // obstaculo
        virtual void gerarObstaculos() = 0;

        virtual void executar();
    };
}
