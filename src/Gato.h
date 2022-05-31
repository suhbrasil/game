#pragma once

#include "Colidivel.h"
#include "IdsDesenhaveis.h"

namespace entidades {
    class Gato : public Colidivel
    {
    private:

    public:
        Gato(Vetor2F pos, Vetor2F vel);
        ~Gato();
        void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);
    };
}