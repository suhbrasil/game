#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include <SFML/Graphics.hpp>

namespace entidades {
    class Personagem
    {
    private:
        sf::Vector2f posicao;
        sf::Vector2f v;
        sf::Texture* text;
        sf::RectangleShape corpo;
    public:
        Personagem(sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f), const char* caminhoTextura = nullptr);
        ~Personagem();
        void atualizar(float t);
        void desenhar(sf::RenderWindow* janela);
    };
}


#endif
