#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "Ente.h"
#include "Fase.h"
#include "ListaEntidades.h"

using namespace sf;
using namespace std;
using namespace personagens;
using namespace lista;

namespace fases{

    class Fase : public Ente {

    protected:

       Event event;

        // Tela
        RenderWindow janela;
        Sprite fundoTela;
        Texture fundoTelaTex;

        // Jogador
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
    int gerarAleatoriamente(int menor);
    void gerarObstaculos();

    void executar();
    };
}
