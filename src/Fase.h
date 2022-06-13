#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Projetil.h"
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
        int perdeu;
        int qtdJogadores;
        Event event1;
        Event event2;
        RenderWindow* janela;
        GerenciadorColisoes gerenciadorColisao;
        GerenciadorGrafico* gerenciadorGrafico;

        Sprite fundoTela;
        Texture fundoTelaTex;
        Sprite portal;
        Texture portalTex;

        Jogador* jogador1;
        Jogador* jogador2;
    public:
        Fase(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf);
        ~Fase();

        // Tela
        void inicializarPortal(float x);
        void inicializarFundoTela(const char* caminho);
        void renderFundoTela();
        Texture getFundoTela();

        // Pausar jogada
        void salvarJogada();
        void pausarJogada();

        // Pontos
        void verPontos();

        // Jogador
        void inicializarJogador(Jogador* j1, Jogador* j2);
        virtual void atualizarRenderObstaculos() = 0;
        virtual void atualizarRenderInimigos() = 0;
        void atualizarJogador1();
        void atualizarJogador2();
        void atualizar1();
        void atualizar2();
        void atualizarRenderJogador();
        void atualizarColisao();
        void render();
        int gerarAleatoriamente(int maior, int menor);

        // obstaculo
        virtual void gerarObstaculos() = 0;
        virtual void gerarInimigos() = 0;

        // Numero de jogadores
        void setQtdJogadores(int qtd);
        int getQtdJogadores();

        void setPerdeu(int p);
        int getPerdeu();

        void executar();
    };
}
