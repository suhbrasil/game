#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Colidivel.h"
#include "IdsDesenhaveis.h"

namespace entidades {
    class Inimigo : public Colidivel
    {
    private:

    public:
        Inimigo(Vetor2F pos, Vetor2F vel);
        ~Inimigo();
        void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);
    };
}

#endif
