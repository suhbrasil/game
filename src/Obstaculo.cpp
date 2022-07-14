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
