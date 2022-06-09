#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "Ente.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Obstaculo.h"

using namespace sf;
using namespace std;
using namespace personagens;
using namespace obstaculos;

namespace fases{
    class Fase : public Ente {
    protected:
        // ListaEntidades obstaculos;
        // // ListaEntidades inimigos;
        // RenderWindow janela;
        // Event event;
        // Obstaculo* obstaculo;
        Jogador* jogador;
    public:
        Fase(Jogador* j);
        ~Fase();



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
    void atualizarColisao();
    void render();
    int gerarAleatoriamente();

    void executar();
    };
}
