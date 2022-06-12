#pragma once

#include <SFML/Graphics.hpp>
#include "Inimigo.h"
using namespace sf;

namespace personagens {
    class Rainha : public Inimigo {
    private:

    public:
        Rainha();
        ~Rainha();
        void inicializarTextura();
        void inicializarDesenhavel();
        void inicializarVariaveis();
        float operator+(float i);
        void setPosicao(int i);
    };
}
