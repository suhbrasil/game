#include "Rainha.h"
using namespace personagens;

Rainha::Rainha() : Inimigo() {
    id = 16;

    inicializarTextura();
    inicializarDesenhavel();
}

Rainha::~Rainha() {

}

void Rainha::inicializarTextura() {
    if (!textura.loadFromFile("texture/rainha_ma.png"))
    {
        printf("imagem não encontrada");
    }
}

void Rainha::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.7f, 0.7f);
}

float Rainha::operator+(float i){
    float intervalo = 400.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Rainha::setPosicao(int i) {

    float posicao = operator+(i);
    desenhavel.setPosition(520.f, 450.f);
    this->posicaoX = posicao;


}
