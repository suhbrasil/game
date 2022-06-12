#include "Rainha.h"
using namespace personagens;

Rainha::Rainha() : Inimigo() {
    id = 16;

    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
}

Rainha::~Rainha() {

}

void Rainha::inicializarVariaveis(){

    posicaoX = 5000.f;
    velocidade.x = -2.f;
}

void Rainha::inicializarTextura() {
    if (!textura.loadFromFile("texture/rainha_ma.png"))
    {
        printf("imagem não encontrada");
    }
}

void Rainha::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(1.2f, 1.2f);
}

float Rainha::operator+(float i){
    float intervalo = 2000.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Rainha::setPosicao(int i) {
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 300.f);
    this->posicaoX = posicao;
}
