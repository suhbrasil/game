#pragma once

#include <SFML/Graphics.hpp>
#include "Obstaculo.h"
using namespace sf;

namespace obstaculos {
    class Cogumelo : public Obstaculo {
    private:

    public:
        Cogumelo();
        ~Cogumelo();
        void inicializarTextura();
        void inicializarDesenhavel();
        float operator+(float i);
        void setPosicao(int i);
    };
}
