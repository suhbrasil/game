#include "Ente.h"

#include<iostream>

namespace entidades
{
    Ente::Ente(Vetor2F pos, Vetor2F vel, IdsDesenhaveis::IdsDesenhaveis ID, const char* caminhoTextura) : posicao(pos), v(vel), caminho(caminhoTextura), id(ID) {
    }

    Ente::~Ente() {
    }

    void Ente::inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
        gf.carregarTextura(caminho);
    }

    void Ente::atualizar(float t) {
        posicao += v*t;
        // corpo.move(v*t);
    }

    void Ente::desenhar(GerenciadorGrafico &g) {
        g.desenhar(caminho, posicao);
    }

    const Vetor2F Ente::getPosicao() const {
        return posicao;
    }

    const Vetor2F Ente::getDimensoes() const {
        return dimensoes;
    }

    const IdsDesenhaveis::IdsDesenhaveis Ente::getID() const {
        return id;
    }
}
