#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Fase {

private:

    Sprite desenhavel;
    const bool comDano;

public:
    Fase(Texture& texture, IntRect textureRect,bool comDano=false);
    ~Fase();

    const FloatRect getGlobalBounds() const;
    void atualizar();
    void render(RenderTarget& target);
};
