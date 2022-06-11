#include "Galho.h"
using namespace obstaculos;

Galho::Galho(): Obstaculo() {
    id = 8;

    inicializarTextura();
    inicializarDesenhavel();
}

Galho::~Galho() {

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
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 450.f);
    this->posicaoX = posicao;
}

float Galho::operator+(float i){
    float intervalo = 350.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
