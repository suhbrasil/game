#include "Obstaculo.h"
using namespace obstaculos;

Obstaculo::Obstaculo() {

}

Obstaculo::~Obstaculo() {

}

int Obstaculo::gerarAleatoriamente() {

    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int maior = 5;
    int menor = 3;
    int aleatorio = rand()%(maior-menor+1) + menor;

    return aleatorio;

}

void Obstaculo::setPosicao() {

    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int maior = 1000;
    int menor = 100;
    int aleatorio = rand()%(maior-menor+1) + menor;

    this->y = 632.0f;
    this->x = static_cast<float>(aleatorio);
}
