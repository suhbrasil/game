#include "Inimigo.h"
using namespace personagens;
using namespace entidades;

Inimigo::Inimigo() : Personagem() {
    id = 10;

    inicializarVariaveis();
}

Inimigo::~Inimigo() {
}

void Inimigo::inicializarDesenhavel() {
     desenhavel.setTexture(textura);
     desenhavel.setScale(0.2f,0.2f);
}

void Inimigo::inicializarVariaveis() {
    dano = false;
    posicaoX = 400.f;
    ePlataforma = false;
    eEspinho = false;
    velocidade.x = 2.f;
    velocidade.y = 0.f;
}


void Inimigo::inicializarTextura()
{

}

void Inimigo::atualizar() {
    desenhavel.move(velocidade);
}

const Vector2f Inimigo::getVelocidade() const {
    return velocidade;
}
