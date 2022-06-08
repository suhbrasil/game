#include "Entidade.h"
using namespace entidades;

Entidade::Entidade() {

}

Entidade::~Entidade() {

}

const FloatRect Entidade::getGlobalBounds() const {

    return desenhavel.getGlobalBounds();
}

void Entidade::setPosition(const float x, const float y) {
    desenhavel.setPosition(x,y);
}

const Vector2f Entidade::getPosition() const {
    desenhavel.getPosition();
}

void Entidade::render(RenderTarget &target)
{
    target.draw(desenhavel);
}

void Entidade::inicializarDesenhavel()
{
    desenhavel.setTexture(textura);
    frameAtual = IntRect(0, 0, 45, 34);
    desenhavel.setTextureRect(frameAtual);
    // pra mudar o tamanho do desenho
    desenhavel.setScale(2.0f, 2.0f);
}

void Entidade::inicializarAnimacao()
{
    timerAnimacao.restart();
}

void Entidade::resetTimerAnimacao() {

    timerAnimacao.restart();
}
