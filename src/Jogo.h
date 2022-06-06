#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Menu.h"
using namespace entidades;
using namespace gerenciadores;

class Jogo {

private:
    Event event;

    // Tela
    GerenciadorGrafico gerenciadorGrafico;
    RenderWindow janela;
    // Sprite fundoTela;
    // Texture fundoTelaTex;

    // Jogador
    Jogador* jogador;
public:
    Jogo();
    ~Jogo();

    // Tela

    // void inicializarJanela();
    // const RenderWindow& getJanela() const;
    // void inicializarFundoTela();
    // void renderFundoTela();

    // Jogador
    void inicializarJogador();
    void atualizarJogador();
    void atualizar();
    void atualizarRenderJogador();
    void atualizarColisao();
    void render();

    void executar();
};
