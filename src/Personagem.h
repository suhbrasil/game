#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

namespace entidades {
    class Personagem
    {
    private:
        Vetor2F posicao;
        Vetor2F v;
        const char* caminho;
    public:
        Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura = nullptr);
        virtual ~Personagem();
        virtual void inicializar(GerenciadorGrafico &gf, GerenciadorEventos &ge);
        virtual void atualizar(float t);
        virtual void desenhar(GerenciadorGrafico &g);
    };
}


#endif
