#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Vetor2D.h"
#include "GerenciadorGrafico.h"

namespace entidades {
    class Personagem
    {
    private:
        Vetor2F posicao;
        Vetor2F v;
        const char* caminho;
    public:
        Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura = nullptr);
        ~Personagem();
        void inicializar(GerenciadorGrafico &g);
        void atualizar(float t);
        void desenhar(GerenciadorGrafico &g);
    };
}


#endif
