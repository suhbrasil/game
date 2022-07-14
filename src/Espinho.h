#pragma once

#include <SFML/Graphics.hpp>
#include "Obstaculo.h"

using namespace sf;

namespace obstaculos {
    class Espinho : public Obstaculo {

    protected:

    public:
        Espinho();
        ~Espinho();
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        void setPosicao(int i);
        float operator+(float i);
        void executar() {}
    };
}
