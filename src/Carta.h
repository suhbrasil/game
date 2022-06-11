#pragma once

#include <SFML/Graphics.hpp>
#include "Inimigo.h"
using namespace sf;

namespace personagens {
    class Carta : public Inimigo {
    private:

    public:
        Carta();
        ~Carta();
        void inicializarTextura();
        void inicializarDesenhavel();
        float operator+(float i);
        void setPosicao(int i);
    };
}
