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
        void inicializar(GerenciadorGrafico &gf, GerenciadorColisoes &gc);
        void atualizar(float t);
        void desenhar(GerenciadorGrafico &g);
        void tratarObstaculo(const sf::Event& e);
    };
}


#endif
