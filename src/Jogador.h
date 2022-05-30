#ifndef _JOGADOR_H_
#define _JOGADOR_H_

// #include "Ente.h"
#include "Colidivel.h"

namespace entidades {
    class Jogador : public Colidivel
    {
    protected:
        unsigned int chaveOuvinte;
    public:
        Jogador(Vetor2F pos);
        ~Jogador();
        void inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void atualizar(float t);
        void desenhar(GerenciadorGrafico& g);
        void tratarEventos(const sf::Event& e);
        void colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro);
    };
}


#endif
