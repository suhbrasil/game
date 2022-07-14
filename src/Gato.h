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
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        void setPosicao(int i);
        float operator+(float i);
        float operator-(float i);
    };
}
