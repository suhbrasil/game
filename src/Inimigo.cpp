#include "Inimigo.h"

#include <iostream>

namespace entidades {
    Inimigo::Inimigo(Vetor2F pos, Vetor2F vel) : Colidivel(pos, vel, IdsDesenhaveis::inimigo, "/Users/suzanabrasil/game/src/rainha_ma.png") { }

    Inimigo::~Inimigo() { }

    void Inimigo::inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
        gf.carregarTextura(caminho);
        dimensoes = gf.getTamanho(caminho);
        gc.adicionarColidivel(this);
    }

    void Inimigo::colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) {
        if(IDOutro == IdsDesenhaveis::jogador) {
            // se colidir com o jogador (heroi)
            std::cout << "Comeu um pedaço do heroi" << std::endl;
        } else if(IDOutro == IdsDesenhaveis::inimigo) {
            Vetor2F distancia = posicao - posicaoOutro;
            posicao += distancia*(1/2);
            // se colidir com outro inimigo pede desculpa e muda de sentido
            std::cout << "Desculpa" << std::endl;
            v *= -1;
        }
    }
}
