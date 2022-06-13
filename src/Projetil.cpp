#include "Projetil.h"
using namespace entidades;

Projetil::Projetil() : Entidade() {
    id = 9;
    inicializarDesenhavel();
    inicializarVariaveis();
}

Projetil::~Projetil() {
}

void Projetil::inicializarVariaveis() {
}

void Projetil::atualizar(Vector2f velocidadeInimigo) {
}

void Projetil::inicializarDesenhavel() {
    shape.setFillColor(Color::Red);
    shape.setRadius(7.f);
}
