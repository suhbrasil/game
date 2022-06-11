#include "Carta.h"
using namespace personagens;

Carta::Carta() : Inimigo() {
    id = 1;
    inicializarTextura();
    inicializarDesenhavel();
}

Carta::~Carta() {

}

void Carta::inicializarTextura() {
    if (!textura.loadFromFile("texture/carta.png"))
    {
        printf("imagem não encontrada");
    }
}

void Carta::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.5f, 0.5f);
}

float Carta::operator+(float i){
    float intervalo = 400.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Carta::setPosicao(int i) {

    float posicao = operator+(i);
    desenhavel.setPosition(700.f, 580.f);
    this->posicaoX = posicao;
}
