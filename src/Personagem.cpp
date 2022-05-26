#include "Personagem.h"

#include<iostream>

namespace entidades
{
    Personagem::Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura) : posicao(pos), v(vel), caminho(caminhoTextura) {
    }

    Personagem::~Personagem() {
    }

    void Personagem::inicializar(GerenciadorGrafico &gf, GerenciadorEventos &ge) {
        gf.carregarTextura(caminho);
    }

    void Personagem::atualizar(float t) {
        posicao += v*t;
        // corpo.move(v*t);
    }

    void Personagem::desenhar(GerenciadorGrafico &g) {
        g.desenhar(caminho, posicao);
    }
}
