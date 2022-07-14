#include "Rainha.h"
using namespace personagens;

Rainha::Rainha() : Inimigo() {
    id = 16;

    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
    inicializarFenomenosFisicos();
    atualizarFenomenosFisicos();
}

Rainha::~Rainha() {

}

void Rainha::atualizar() {
    desenhavel.move(velocidade);
    centro.x = desenhavel.getPosition().x + desenhavel.getGlobalBounds().width/2-50.f;
    centro.y = desenhavel.getPosition().y + desenhavel.getGlobalBounds().height/2- 50.f;
}

void Rainha::inicializarVariaveis(){

    posicaoX = 3900.f;
    velocidade.x = -2.f;
    centro.x = desenhavel.getPosition().x + desenhavel.getGlobalBounds().width/2-50.f;
    centro.y = desenhavel.getPosition().y + desenhavel.getGlobalBounds().height/2- 50.f;

}

void Rainha::inicializarTextura() {
    if (!textura.loadFromFile("texture/rainha_ma.png"))
    {
        printf("imagem não encontrada");
    }
}

void Rainha::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(1.f, 1.f);
}

float Rainha::operator+(float i){
    float intervalo = 2000.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}

void Rainha::setPosicao(int i) {
    float posicao = operator+(i);
    desenhavel.setPosition(posicao, 400.f);
    this->posicaoX = posicao;
}
