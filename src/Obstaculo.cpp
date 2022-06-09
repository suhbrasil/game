#include "Obstaculo.h"
using namespace obstaculos;
using namespace entidades;

Obstaculo::Obstaculo() : Entidade() {
    inicializarVariaveis();
    inicializarTextura();
    inicializarDesenhavel();
    setPosicao();
}

Obstaculo::~Obstaculo() {
}

void Obstaculo::inicializarDesenhavel() {
     desenhavel.setTexture(textura);
     desenhavel.setScale(0.2f,0.2f);
}

void Obstaculo::inicializarVariaveis() {
    dano = false;
    quantidadeInstancias = 0;
}

void Obstaculo::inicializarTextura()
{   printf("text");
    if (!textura.loadFromFile("texture/cogumelo.png"))
    {
        printf("imagem não encontrada");
    }
}

int Obstaculo::gerarAleatoriamente() {
    srand((unsigned)time(NULL)); //para gerar números aleatórios reais.
    int maior = 5;
    int menor = 3;
    int aleatorio = rand()%(maior-menor+1) + menor;

    return aleatorio;
}

void Obstaculo::setPosicao() {
    srand((unsigned)time(NULL)); //para gerar números aleatórios reais.
    int maior = 1000;
    int menor = 100;
    int aleatorio = rand()%(maior-menor+1) + menor;

    this->y = 632.0f;
    this->x = static_cast<float>(aleatorio);
    desenhavel.setPosition(this->x, this->y);
}
