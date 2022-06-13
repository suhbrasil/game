#include "Galho.h"
using namespace obstaculos;

Galho::Galho(): Obstaculo() {
    id = 8;
    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
}

Galho::~Galho() {

}

void Galho::inicializarVariaveis() {
    ePlataforma = true;
    posicaoX = 1000.f;
    posicaoY = 500.f;
}

void Galho::inicializarTextura()
{
    if (!textura.loadFromFile("texture/tronco.png"))
    {
        printf("imagem não encontrada");
    }
}

void Galho::inicializarDesenhavel() {
     desenhavel.setTexture(textura);
     desenhavel.setScale(0.6f,0.4f);
}

void Galho::setPosicao(int i) {
    float posY = operator-(i);
    float posX = operator+(i);
    desenhavel.setPosition(posX,posY);
    this->posicaoX = posX;
    this->posicaoY = posY;
}

float Galho::operator+(float i){
    float intervalo = 500.f;
    intervalo *= i;
    return this->posicaoX + intervalo;
}

float Galho::operator-(float i){
    float intervalo = 75.f;
    intervalo *= i;
    return this->posicaoY - intervalo;
}
