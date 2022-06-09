#pragma once
#include <iostream>
#include "Inimigo.h"
#include <vector>
#include <list>
#include "Obstaculo.h"
#include "ListaEntidades.h"
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
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        // void inicializarObjetos(ListaEntidades* listaEntidades);
        bool estaoColidindo(Entidade* p1, Entidade* p2);
        void verificarColisoes();

    };

}
