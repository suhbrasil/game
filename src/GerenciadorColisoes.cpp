#include "GerenciadorColisoes.h"
using namespace gerenciadores;

GerenciadorColisoes::GerenciadorColisoes() {
    obstaculo = new Obstaculo();
}

GerenciadorColisoes::~GerenciadorColisoes() {
    delete obstaculo;
}

void GerenciadorColisoes::adicionarObstaculo(Obstaculo* obstaculo) {
    // obstaculos.push_front(obstaculo);
}

Obstaculo* GerenciadorColisoes::getObstaculo() {
    return obstaculo;
}

bool GerenciadorColisoes::estaoColidindo(Entidade* p1, Entidade* p2) {

}

void GerenciadorColisoes::verificarColisoes(RenderWindow& janela, Jogador* jogador) {
        if(jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela.getSize().y) {
            jogador->resetVelocidadeY();
            jogador->setPosition(jogador->getGlobalBounds().left,
                    janela.getSize().y - jogador->getGlobalBounds().height);

            FloatRect jogadorLimites = jogador->getGlobalBounds();
            FloatRect obstaculoLimites = obstaculo->getGlobalBounds();
            // proxPosicao vai pegar a proxima posicao do elemento antes dele se mexer
            proxPosicao = jogadorLimites;
            proxPosicao.left += jogador->getVelocidade().x;
            proxPosicao.top += jogador->getVelocidade().y;

            if(obstaculoLimites.intersects(proxPosicao))
                cout << "COLISAO!" << endl;
        }
}
