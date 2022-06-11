#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Cogumelo.h"
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

        ListaEntidades galhos;
        ListaEntidades cogumelos;
    public:
        FaseDois(Jogador* j, GerenciadorGrafico* gf);
        ~FaseDois();

        // Jogador
        void atualizarRenderGalhos(int pos);
        void atualizarRenderCogumelos(int pos);
        void atualizarRenderObstaculos();

        // obstaculo
        void gerarCogumelos();
        void gerarGalhos();
        void gerarObstaculos();

    };
}
