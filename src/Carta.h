#pragma once

#include <SFML/Graphics.hpp>
#include "Inimigo.h"
#include "Projetil.h"
using namespace sf;

namespace personagens {
    class Carta : public Inimigo {
    private:
        int tempoTiro;
        Vector2f centro;
    public:
        vector<Projetil*> projeteis;
        Carta();
        ~Carta();
        void inicializarTextura();
        void inicializarDesenhavel();
        void inicializarVariaveis();
        float operator+(float i);
        void setPosicao(int i);
        void setPosicao2(int i);
        float operator-(float i);
        float operator/(float i);
    };
}
