#include "Fase.h"
using namespace fases;

Fase::Fase(Texture& texture, IntRect textureRect, bool comDano) : Ente(),
comDano(comDano)
{
    desenhavel.setTexture(texture);
    desenhavel.setTextureRect(textureRect);
}

Fase::Fase() : Ente(), comDano(false) {}

Fase::~Fase() {

}

const FloatRect Fase::getGlobalBounds() const {
    return desenhavel.getGlobalBounds();
}

void Fase::atualizar() {

}

void Fase::render(RenderTarget& target) {
    target.draw(desenhavel);
}
