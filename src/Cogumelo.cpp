#include "Cogumelo.h"
using namespace obstaculos;

Cogumelo::Cogumelo() : Obstaculo() {
    id = 2;

    inicializarTextura();
    inicializarDesenhavel();
}

Cogumelo::~Cogumelo() {

}

void Cogumelo::inicializarVariaveis() {

    posicaoX = 1000.f;

}

void Cogumelo::inicializarTextura() {
    if (!textura.loadFromFile("texture/cogumelo.png"))
    {
        printf("imagem não encontrada");
    }
}

void Cogumelo::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.31f, 0.23f);
}

float Cogumelo::operator+(float i){
    float intervalo = 1200.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Cogumelo::setPosicao(int i) {
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 630.f);
    this->posicaoX = posicao;
}
