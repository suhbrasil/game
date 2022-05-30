#ifndef _ENTE_H_
#define _ENTE_H_

#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"
#include "IdsDesenhaveis.h"

namespace entidades {
    class Ente
    {
    protected:
        Vetor2F posicao;
        Vetor2F v;
        Vetor2F dimensoes;
        const char* caminho;
        IdsDesenhaveis::IdsDesenhaveis id;
    public:
        Ente(Vetor2F pos, Vetor2F vel, IdsDesenhaveis::IdsDesenhaveis ID, const char* caminhoTextura = nullptr);
        virtual ~Ente();
        virtual void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        virtual void atualizar(float t);
        virtual void desenhar(GerenciadorGrafico &g);
        const Vetor2F getPosicao() const;
        const Vetor2F getDimensoes() const;
        const IdsDesenhaveis::IdsDesenhaveis getID() const;
    };
}


#endif
