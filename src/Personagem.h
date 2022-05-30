#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"

namespace entidades {
    class Personagem
    {
    protected:
        Vetor2F posicao;
        Vetor2F v;
        const char* caminho;
    public:
        Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura = nullptr);
        virtual ~Personagem();
        virtual void inicializar(GerenciadorGrafico &gf, GerenciadorColisoes &gc);
        virtual void atualizar(float t);
        virtual void desenhar(GerenciadorGrafico &g);
    };
}


#endif
