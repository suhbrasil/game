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
