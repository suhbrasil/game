#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#include "Ente.h"

namespace fases {
    class Fase : public Ente {
    private:
        Sprite desenhavel;
        const bool comDano;
    public:
        Fase(Texture& texture, IntRect textureRect, bool comDano = false);
        Fase();
        ~Fase();

        const FloatRect getGlobalBounds() const;
        void atualizar();
        void render(RenderTarget& target);

        void executar() {}
    };
}
