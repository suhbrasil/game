#ifndef _GERENCIADORCOLISOES_H_
#define _GERENCIADORCOLISOES_H_

#include <set>

namespace entidades {
    class Colidivel;

    class GerenciadorColisoes
    {
    private:
        // O set funciona como um conjunto matemático, ou seja, só pode ter uma vez cada valor
        // Nesse caso set é melhor que vector, pois está lidando com ponteiro
        std::set<Colidivel*> colidiveis;
        bool estaoColidindo(Colidivel* p1, Colidivel* p2);
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        void adicionarColidivel(Colidivel* p);
        void removerColidivel(Colidivel* p);
        void removerTodos();
        void verificarColisoes();
    };
}


#endif
