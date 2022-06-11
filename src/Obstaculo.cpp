#include "Obstaculo.h"
using namespace obstaculos;
using namespace entidades;

Obstaculo::Obstaculo() : Entidade() {
    id = 13;

    inicializarVariaveis();
}

Obstaculo::~Obstaculo() {
}

void Obstaculo::inicializarDesenhavel() {
     desenhavel.setTexture(textura);
     desenhavel.setScale(0.2f,0.2f);
}

void Obstaculo::inicializarVariaveis() {
    dano = false;
    posicaoX = 200;
    ePlataforma = false;
    eEspinho = false;
}

const bool Obstaculo::getEPlataforma() const {
    return ePlataforma;

}

const bool Obstaculo::getEEspinho() const {
    return eEspinho;

}

void Obstaculo::inicializarTextura()
{

}
void Obstaculo::setPosicao(int i) {
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 500.f);
    this->posicaoX = posicao;

}

float Obstaculo::operator+(float i){
    float intervalo = 250.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
