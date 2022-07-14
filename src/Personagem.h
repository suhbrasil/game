#pragma once

#include "Entidade.h"
using namespace entidades;

namespace personagens {
    class Personagem : public Entidade
    {
    protected:
        Vector2f posicao;
        Vector2f velocidade;

        float velocidadeMaxima;
        float velocidadeMinima;
        float aceleracao;
        float atrito;
        float gravidade;
        float velocidadeMaximaY;
        float velocidadeMinimaY;
        float posicaoInicialY;
        float posicaoInicialX;
        float alturaPulo;
    public:
        Personagem(Vector2f pos = Vector2f(0.0f, 0.0f), Vector2f v = Vector2f(0.0f, 0.0f));
        ~Personagem();

        void resetVelocidadeX();
        void resetVelocidadeY();
        void inicializarFenomenosFisicos();
        void atualizarFenomenosFisicos();
        void inverterVelocidade();
        void atualizar();
    };
}
