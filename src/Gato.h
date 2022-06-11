#pragma once

#include <SFML/Graphics.hpp>
#include "Inimigo.h"
using namespace sf;

namespace personagens {
    class Gato : public Inimigo {
    private:

    public:
        Gato();
        ~Gato();
        void inicializarTextura();
        void inicializarDesenhavel();
        float operator+(float i);
        void setPosicao(int i);
    };
}
