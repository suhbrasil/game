#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Cogumelo.h"
#include "Gato.h"
#include "Rainha.h"
#include "Galho.h"
using namespace obstaculos;
using namespace entidades;
using namespace personagens;
using namespace sf;
using namespace lista;

namespace fases
{
    class FaseDois : public Fase
    {

    private:
        int qtdeGalhos;
        int qtdeCogumelos;

        int qtdeGatos;
        int qtdeRainhas;

        ListaEntidades galhos;
        ListaEntidades cogumelos;

        ListaEntidades gatos;
        ListaEntidades rainhas;
    public:
        FaseDois(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf);
        ~FaseDois();

        // Inimigos
        void gerarGatos();
        void gerarRainhas();
        void gerarInimigos();

        // obstaculo
        void gerarCogumelos();
        void gerarGalhos();
        void gerarObstaculos();

        void atualizarRenderGatos(int pos);
        void atualizarRenderRainhas(int pos);
        void atualizarRenderGalhos(int pos);
        void atualizarRenderCogumelos(int pos);
        void atualizarRenderInimigos();
        void atualizarRenderObstaculos();
    };
}
