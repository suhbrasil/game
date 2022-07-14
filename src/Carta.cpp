#include "Carta.h"
using namespace personagens;

Carta::Carta() : Inimigo() {
    id = 1;
    inicializarTextura();
    inicializarDesenhavel();
    inicializarVariaveis();
    inicializarFenomenosFisicos();
    atualizarFenomenosFisicos();
}

Carta::~Carta() {

}

void Carta::inicializarVariaveis() {
    posicaoX = 1300.f;
}

void Carta::inicializarTextura() {
    if (!textura.loadFromFile("texture/carta.png"))
    {
        printf("imagem não encontrada");
    }
}

void Carta::inicializarDesenhavel() {
    desenhavel.setTexture(textura);
    desenhavel.setScale(0.5f, 0.5f);
}

void Carta::adicionarProjetil(Projetil* projetil){
    projeteis.push_back(projetil);
}

const int Carta::getTempoTiro() const {
    return tempoTiro;
}

void Carta::setTempoTiro(int tempo) {
    tempoTiro = tempo;
}

vector<Projetil*> Carta::getProjeteis() {
    return projeteis;
}

float Carta::operator+(float i){
    float intervalo = 700.f;
    intervalo*= i;
    return this->posicaoX + intervalo;
}
void Carta::setPosicao(int i) {
    float posX = operator+(i);
    desenhavel.setPosition(posX, 575.f);
    this->posicaoX = posX;
}
