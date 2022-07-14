#include "Projetil.h"
using namespace entidades;

Projetil::Projetil() : Entidade() {
    id = 15;
    inicializarDesenhavel();
    inicializarVariaveis();
}

Projetil::~Projetil() {
}

void Projetil::inicializarDesenhavel() {
    shape.setFillColor(Color::Red);
    shape.setRadius(7.f);
}
