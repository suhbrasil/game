#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "Menu.h"

using namespace sf;
using namespace std;
using namespace entidades;

class Jogo {

private:
    Event event;

    // Tela
    RenderWindow janela;
    Sprite fundoTela;
    Texture fundoTelaTex;

    // Jogador
    Jogador* jogador;
public:
    Jogo();
    ~Jogo();

    // Tela
    void inicializarJanela();
    const RenderWindow& getJanela() const;
    void inicializarFundoTela();
    void renderFundoTela();

    // Jogador
    void inicializarJogador();
    void atualizarJogador();
    void atualizar();
    void atualizarRenderJogador();
    void render();

    void executar();
};
