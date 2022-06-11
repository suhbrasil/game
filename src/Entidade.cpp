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

    return desenhavel.getPosition();
}

void Entidade::render(RenderTarget &target)
{
    target.draw(desenhavel);
}

void Entidade::inicializarDesenhavel()
{
    desenhavel.setTexture(textura);
    //shape.setSize(Vector2f(50.f,50.f));
    //shape.setFillColor(Color::Red);
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


const Vector2f Entidade::getDimensoesMetade() const {
    return dimensoes/2.0f;
}

void Entidade::colidir(Entidade* p, Vector2f posicaoOutro, Vector2f dimensoesOutro) {
    std::cout << "colidiu" << std::endl;
    Vector2f distancia = desenhavel.getPosition() - posicaoOutro;
}
