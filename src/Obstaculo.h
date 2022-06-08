#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace entidades;

namespace obstaculos {
    class Obstaculo : public Entidade {

    protected:
        bool dano;
        int quantidadeInstancias;

    public:
        Obstaculo();
        ~Obstaculo();
        int gerarAleatoriamente();
        void setPosicao();
        virtual void inicializarVariaveis() = 0;
    };
}
