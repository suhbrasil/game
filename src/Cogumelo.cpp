#include "Cogumelo.h"
using namespace obstaculos;

Cogumelo::Cogumelo() : Obstaculo() {
    inicializarTextura();
    inicializarDesenhavel();
}

Cogumelo::~Cogumelo() {

}

void Cogumelo::inicializarTextura() {
    if (!textura.loadFromFile("texture/cogumelo.png"))
    {
        printf("imagem não encontrada");
    }
}

void Cogumelo::inicializarDesenhavel() {
    // // desenhavel.setColor(Color::Red);
    // desenhavel.setTexture(textura);
    // desenhavel.setScale(2.0f, 2.0f);
    // setPosicao();
    // obstaculos.push_back(desenhavel);
}
