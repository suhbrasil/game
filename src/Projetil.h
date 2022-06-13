#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"
using namespace sf;

namespace entidades {
    class Projetil : public Entidade {
    private:

    public:
        CircleShape shape;
        Projetil();
        ~Projetil();
        void inicializarTextura();
        void inicializarDesenhavel();
        void inicializarVariaveis();
        void atualizar(Vector2f velocidadeInimigo);
    };
}
