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
        int tempoTiro;

        Projetil* projetil;

        ListaEntidades galhos;
        ListaEntidades espinhos;
        ListaEntidades gatos;
        ListaEntidades cartas;

        vector<Projetil*> projeteis;
    public:
        FaseUm(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf);
        ~FaseUm();

        void gerarGatos();
        void gerarCartas();
        void gerarEspinhos();
        void gerarGalhos();
        void gerarInimigos();
        void gerarObstaculos();
        void gerarProjeteis();

        void moverProjeteis();

        void atualizarRenderGatos(int i);
        void atualizarRenderCartas(int j);
        void atualizarRenderGalhos(int i);
        void atualizarRenderEspinhos(int j);
        void atualizarRenderInimigos();
        void atualizarRenderObstaculos();
    };
}
