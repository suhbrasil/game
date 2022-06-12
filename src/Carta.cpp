#include "Carta.h"
using namespace personagens;

Carta::Carta() : Inimigo() {
    id = 1;
    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
}

Carta::~Carta() {

}

void Carta::inicializarVariaveis() {

    velocidade.x = 2.f;
    velocidade.y = 0;
    posicaoX = 600.f;

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
    float intervalo = 650.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
void Carta::setPosicao(int i) {
    float posX = operator+(i);
    desenhavel.setPosition(posX, 575.f);
    this->posicaoX = posX;
}

void Carta::setPosicao2(int i) {

    float posY = operator/(i);
    float posX = operator-(i);

    desenhavel.setPosition(posX,posY);
    this->posicaoX = posX;
    this->posicaoY = posY;
}

float Carta::operator-(float i){
    float intervalo = 570.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

float Carta::operator/(float i){
    float intervalo = 75.f;
    intervalo*= i;

    return this->posicaoY - intervalo;
}
