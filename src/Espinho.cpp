#include "Espinho.h"
using namespace obstaculos;

Espinho::Espinho() {

}

Espinho::~Espinho() {

}

void Espinho::inicializarVariaveis() {

    quantidadeInstancias = this->gerarAleatoriamente();

}

void Espinho::inicializarTextura()
{
    if (!textura.loadFromFile("texture/espinho.png"))
    {
        printf("imagem não encontrada");
    }
}
