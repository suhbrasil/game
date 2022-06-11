#include "Galho.h"
using namespace obstaculos;

Galho::Galho(): Obstaculo() {
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
     desenhavel.setScale(0.2f,0.2f);
}

void Galho::setPosicao(int i) {

    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 550.f);
    this->posicaoX = posicao;


}

float Galho::operator+(float i){
    float intervalo = 350.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
