#include "Espinho.h"
using namespace obstaculos;

Espinho::Espinho(): Obstaculo() {
    id = 4;

    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
}

Espinho::~Espinho() {

}

void Espinho::inicializarVariaveis() {
    posicaoX = 1200.f;
}

void Espinho::inicializarDesenhavel() {
     desenhavel.setTexture(textura);
     desenhavel.setScale(0.2f,0.3f);
}

void Espinho::inicializarTextura()
{
    if (!textura.loadFromFile("texture/espinho.png"))
    {
        printf("imagem não encontrada");
    }
}


void Espinho::setPosicao(int i) {
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 610.f);
    this->posicaoX = posicao;
}

float Espinho::operator+(float i){
    float intervalo = 1000.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
