#include "Colidivel.h"
#include "GerenciadorColisoes.h"

#include <math.h>

namespace entidades {
    GerenciadorColisoes::GerenciadorColisoes() { }

    GerenciadorColisoes::~GerenciadorColisoes() { }

   bool GerenciadorColisoes::estaoColidindo(Colidivel* p1, Colidivel* p2) {
       Vetor2F posicao1 = p1->getPosicao();
       Vetor2F dimensoes1 = p1->getDimensoes();

       Vetor2F posicao2 = p2->getPosicao();
       Vetor2F dimensoes2 = p2->getDimensoes();

       Vetor2F distancia = posicao1 - posicao2;

       return (fabs(distancia.x) < (dimensoes1.x + dimensoes2.x)/2.0) && (fabs(distancia.y) < (dimensoes1.y + dimensoes2.y)/2.0);
   }

    void GerenciadorColisoes::adicionarColidivel(Colidivel *p) {
        colidiveis.insert(p);
    }

    void GerenciadorColisoes::removerColidivel(Colidivel *p) {
        colidiveis.erase(p);
    }

    void GerenciadorColisoes::removerTodos() {
        colidiveis.clear();
    }

    void GerenciadorColisoes::verificarColisoes() {
        // auto faz com que ao declarar uma variavel deixe o tipo dela igual o tipo que está sendo definido para ela
        for(auto primeiro = colidiveis.begin(); primeiro != colidiveis.end(); primeiro++) {
            auto segundo = primeiro;
            segundo++;
            for(; segundo != colidiveis.end(); segundo++) {
                Colidivel *p1 = *primeiro;
                Colidivel *p2 = *segundo;
                if(estaoColidindo(p1, p2)) {
                    p1->colidir(p2->getID(), p2->getPosicao(), p2->getDimensoes());
                    p2->colidir(p1->getID(), p1->getPosicao(), p1->getDimensoes());
                }
            }
        }
    }
}
