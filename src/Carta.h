#pragma once

#include "Colidivel.h"
#include "IdsDesenhaveis.h"

namespace entidades {
    class Carta : public Colidivel
    {
    private:

    public:
        Carta(Vetor2F pos, Vetor2F vel);
        ~Carta();
        void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);
    };
}

