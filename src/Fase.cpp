#include "Fase.h"

Fase::Fase(Texture& texture, IntRect  textureRect, bool dano):
comDano(dano) 
{
    desenhavel.setTexture(texture);
    desenhavel.setTextureRect(textureRect);
}

Fase:: ~Fase() {

}

const FloatRect Fase::getGlobalBounds() const {
    return desenhavel.getGlobalBounds();

}

void Fase::atualizar() {

}

void Fase::render(RenderTarget& target) {
    target.draw(desenhavel);
}