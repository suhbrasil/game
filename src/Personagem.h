#pragma once

#include "Entidade.h"
using namespace entidades;

namespace personagens {
    class Personagem : public Entidade
    {
    protected:
        Vector2f posicao;
        Vector2f velocidade;
    public:
        Personagem(Vector2f pos = Vector2f(0.0f, 0.0f), Vector2f v = Vector2f(0.0f, 0.0f));
        ~Personagem();

        // movimentar os personagens
        void atualizar(float tempo);
    };
}
