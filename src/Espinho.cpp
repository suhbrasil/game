#include "Espinho.h"
using namespace obstaculos;

Espinho::Espinho(): Obstaculo() {

    inicializarTextura();
    inicializarDesenhavel();

}

Espinho::~Espinho() {

}

void Espinho::inicializarVariaveis() {

}

void Espinho::inicializarDesenhavel() {
     desenhavel.setTexture(textura);
     desenhavel.setScale(0.15f,0.15f);
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
    desenhavel.setPosition(posicao, 645.f);
    this->posicaoX = posicao;


}

float Espinho::operator+(float i){
    float intervalo = 350.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
