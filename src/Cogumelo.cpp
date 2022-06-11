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
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.2f, 0.2f);
}

float Cogumelo::operator+(float i){
    float intervalo = 400.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Cogumelo::setPosicao(int i) {

    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 630.f);
    this->posicaoX = posicao;


}
