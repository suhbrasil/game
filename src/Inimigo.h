#pragma once

#include "Personagem.h"

namespace personagens {
    class Inimigo : public Personagem {
    protected:
    public:
        Inimigo(Vector2f pos = Vector2f(0.0f, 0.0f), Vector2f v = Vector2f(0.0f, 0.0f));
        ~Inimigo();
        void inicializarTextura();
    };
}
