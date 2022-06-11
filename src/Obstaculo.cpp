#include "Obstaculo.h"
using namespace obstaculos;
using namespace entidades;

Obstaculo::Obstaculo() : Entidade() {
    inicializarVariaveis();
    //inicializarTextura();
    //inicializarDesenhavel();
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
}

void Obstaculo::inicializarTextura()
{

}

int Obstaculo::gerarAleatoriamente(int maior, int menor) {
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int aleatorio = rand()%(maior-menor+1) + menor;

    return aleatorio;
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
