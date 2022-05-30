#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"

namespace entidades {
    class Jogador : public Personagem
    {
    protected:
        unsigned int chaveOuvinte;
    public:
        Jogador(Vetor2F pos);
        ~Jogador();
        void inicializar(GerenciadorGrafico &gf, GerenciadorEventos &ge);
        void atualizar(float t);
        void desenhar(GerenciadorGrafico &g);
        void tratarEventos(const sf::Event& e);
    };
}


#endif
