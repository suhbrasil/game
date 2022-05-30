#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

namespace entidades {
    class Inimigo : public Personagem
    {
    private:

    public:
        Inimigo(Vetor2F pos, Vetor2F vel);
        ~Inimigo();
    };
}

#endif
