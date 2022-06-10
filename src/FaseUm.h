#pragma once

#include <SFML/Graphics.hpp>
#include <fstream> // ofstream e ifstream
#include "Jogador.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Espinho.h"
#include "Galho.h"
using namespace obstaculos;
using namespace entidades;
using namespace personagens;
using namespace sf;
using namespace lista;

namespace fases
{
    class FaseUm : public Fase
    {

    private:
        int qtdeGalhos;
        int qtdeEspinhos;

        // Tela
        Event event;
        RenderWindow janela;
        GerenciadorColisoes gerenciadorColisao;
        Sprite fundoTela;
        Texture fundoTelaTex;
        Vector2i posMouse;
        Vector2f coordMouse;

        // Texto pause
        Font fonte;
        Text texto;

        ListaEntidades galhos;
        ListaEntidades espinhos;
    public:
        FaseUm(Jogador *j);
        ~FaseUm();

        // Tela
        void inicializarJanela();
        const RenderWindow& getJanela() const;
        void inicializarFundoTela();
        void renderFundoTela();

        // Pausar jogada
        void inicializarBotaoPausar();
        void salvarJogada();
        void pausarJogada();

        // Jogador
        void inicializarJogador(Jogador* j);
        void inicializarObstaculos();
        void atualizarRenderObstaculos();
        void atualizarRenderGalhos(int pos);
        void atualizarRenderEspinhos(int pos);
        void atualizarJogador();
        void atualizar();
        void atualizarRenderJogador();
        void atualizarColisao();
        void render();

        // obstaculo
        void gerarEspinhos();
        void gerarGalhos();
        void gerarObstaculos();

        void executar();
    };
}
