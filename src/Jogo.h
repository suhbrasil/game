#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Menu.h"
#include "Ranking.h"
#include "Fase.h"
using namespace personagens;
using namespace gerenciadores;
using namespace fases;

class Jogo {
private:
    Event event;
    GerenciadorGrafico gerenciadorGrafico;

    // Menu
    Menu* menu;
    RectangleShape backgroundMenu;
    Texture backgroundTextMenu;

    // Jogo
    RectangleShape background;
    Texture backgroundText;

    // Ranking
    Ranking* ranking;
    RectangleShape backgroundRanking;
    Texture backgroundTextRanking;

    // Fases
    RenderWindow FASE1;

    // Jogador
    Jogador* jogador;
public:
    Jogo();
    ~Jogo();

    // Jogador
    void inicializarJogador();
    void atualizarJogador();
    void atualizar();
    void atualizarRenderJogador();
    void atualizarColisao();
    void render();

    void executar();
};
