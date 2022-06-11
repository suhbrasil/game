#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "Fase.h"
#include "ListaEntidades.h"
#include "Lista.h"
#include "Espinho.h"
#include "Galho.h"
#include "Carta.h"
#include "Gato.h"
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

        int qtdeGatos;
        int qtdeCartas;

        ListaEntidades galhos;
        ListaEntidades espinhos;

        ListaEntidades gatos;
        ListaEntidades cartas;

    public:
        FaseUm(Jogador* j, GerenciadorGrafico* gf);
        ~FaseUm();

        // Jogador
        void atualizarRenderGalhos(int pos);
        void atualizarRenderEspinhos(int pos);
        void atualizarRenderObstaculos();
        void atualizarRenderInimigos();

        // obstaculo
        void gerarEspinhos();
        void gerarGalhos();
       // void gerarGatos();
        //void gerarCartas();
        void gerarObstaculos();
        //void gerarInimigos();
    };
}
