#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Menu.h"
#include "Ranking.h"
#include "Fase.h"
using namespace entidades;
using namespace gerenciadores;
using namespace fases;

class Jogo {
private:
    Event event;
    GerenciadorGrafico gerenciadorGrafico;
    Ranking nomeJogador;

    // Menu
    Menu* menu;
    RectangleShape backgroundMenu;
    Texture backgroundTextMenu;

    // Jogo
    RectangleShape background;
    Texture backgroundText;

    // Ranking
    RectangleShape backgroundRanking;
    Texture backgroundTextRanking;

    // Fases
    RenderWindow FASE1;
    RenderWindow FASE2;

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
