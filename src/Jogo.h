#pragma once

#include <stack>
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Ente.h"
#include "Menu.h"
#include "Ranking.h"
#include "Fase.h"
#include "FaseUm.h"
#include "FaseDois.h"
using namespace personagens;
using namespace gerenciadores;
using namespace fases;


class Jogo {
private:
    Event event;
    GerenciadorGrafico gerenciadorGrafico;

    // Menu
    RectangleShape backgroundMenu;
    Texture backgroundTextMenu;
    // Jogo
    RectangleShape background;
    Texture backgroundText;
    // Ranking
    RectangleShape backgroundRanking;
    Texture backgroundTextRanking;

    stack<Ente*> pilha;
    int proximo;
    Menu* menu;
    FaseUm* faseUm;
    FaseDois* faseDois;
    Ranking* ranking;

    Jogador* jogador;
public:
    Jogo();
    ~Jogo();

    void inicializar();
    // void atualizarJogador();
    // void atualizar();

    void executar();
};
