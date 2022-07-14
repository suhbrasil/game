#pragma once

#include <SFML/Graphics.hpp>
#include "Projetil.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
using namespace sf;
using namespace entidades;
using namespace lista;

namespace personagens {
    class Rainha : public Inimigo {
    private:
        ListaEntidades projeteis;
        Vector2f centro;
    public:
        Rainha();
        ~Rainha();
        void inicializarTextura();
        void inicializarDesenhavel();
        void inicializarVariaveis();
        void atualizar();
        float operator+(float i);
        void setPosicao(int i);
    };
}
