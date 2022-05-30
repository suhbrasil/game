#ifndef _COLIDIVEL_H_
#define _COLIDIVEL_H_

#include "Ente.h"
#include "IdsDesenhaveis.h"

namespace entidades {
    class Colidivel : public Ente
    {
    public:
        Colidivel(Vetor2F pos, Vetor2F vel, IdsDesenhaveis::IdsDesenhaveis ID, const char* caminhoTextura = nullptr);
        // metodo virual puro que faz a classe se tornar abstrata
        virtual void colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) = 0;
    };
}

#endif
