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
}


void Inimigo::inicializarTextura()
{

}

void Inimigo::setPosicao(int i) {
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 500.f);
    this->posicaoX = posicao;

}

float Inimigo::operator+(float i){
    float intervalo = 450.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
