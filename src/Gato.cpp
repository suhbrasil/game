#include "Gato.h"
using namespace personagens;

Gato::Gato() : Inimigo() {
    id = 9;
    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
}

Gato::~Gato() {

}

void Gato::inicializarVariaveis() {
    posicaoX = 200.f;
    posicaoY = 450.f;
    velocidade.x = 2.f;
    velocidade.y = 0;
}

void Gato::inicializarTextura() {
    if (!textura.loadFromFile("texture/gato.png"))
    {
        printf("imagem não encontrada");
    }
}

void Gato::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.35f, 0.35f);
}
void Gato::setPosicao(int i) {
    float posY = operator-(i);
    float posX = operator+(i);

    desenhavel.setPosition(posX,posY);
    this->posicaoX = posX;
    this->posicaoY = posY;

}

float Gato::operator+(float i){
    float intervalo = 570.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

float Gato::operator-(float i){
    float intervalo = 75.f;
    intervalo*= i;

    return this->posicaoY - intervalo;
}
