#pragma once

#include "Personagem.h"

namespace personagens {
    class Inimigo : public Personagem {
    protected:

    public:
        Inimigo(Vector2f pos, Vector2f v);
        ~Inimigo();
        void inicializarTextura(const char* caminhoText);
    };
}
