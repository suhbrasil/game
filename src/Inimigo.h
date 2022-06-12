#pragma once

#include "Personagem.h"

namespace personagens {
     class Inimigo : public Personagem {
    protected:
        bool dano;
        float posicaoX;
        bool ePlataforma;
        bool eEspinho;
    public:
        Inimigo();
        ~Inimigo();
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        void atualizar();
        void setPosicao(int i);
        void desenharInimigos(RenderWindow& janela);
        const Vector2f getVelocidade() const;
    };
}
