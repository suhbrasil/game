#pragma once

#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "ListaEntidades.h"

#include <iostream>
#include <vector>
#include <list>
#include <math.h>

using namespace personagens;
using namespace obstaculos;
using namespace std;
// using namespace lista;

namespace gerenciadores {
    class GerenciadorColisoes {
    private:
        vector<Inimigo*> inimigos;
        list<Obstaculo*> obstaculos;

        FloatRect proxPosicao;
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        void adicionarObstaculo(Obstaculo* obstaculo);
        Obstaculo* getObstaculo();
        bool estaoColidindo(Jogador *p1, Obstaculo *p2, float push);
        void verificarColisoes(RenderWindow &janela, Jogador *jogador);
        bool verificarColisaoEmBaixo(Jogador*j, Obstaculo* obs);
    };

}
