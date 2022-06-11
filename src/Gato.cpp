#include "Gato.h"
using namespace personagens;

Gato::Gato() : Inimigo() {
    id = 9;
    inicializarTextura();
    inicializarDesenhavel();
}

Gato::~Gato() {

}

void Gato::inicializarTextura() {
    if (!textura.loadFromFile("texture/gato.png"))
    {
        printf("imagem não encontrada");
    }
}

void Gato::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.4f, 0.4f);
}

float Gato::operator+(float i){
    float intervalo = 400.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Gato::setPosicao(int i) {

    float posicao = operator+(i);
    desenhavel.setPosition(500.f, 590.f);
    this->posicaoX = posicao;


}
