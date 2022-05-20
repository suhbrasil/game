#include "Personagem.h"

#include<iostream>

namespace exercicio
{
    Personagem::Personagem(float xInicial, float yInicial, const char *caminhoTextura) {
        x = xInicial;
        y = yInicial;
        text = nullptr;

        // Vector2f é um vetor de 2 dimensões onde as 2 dimensões são float
        corpo.setSize(sf::Vector2f(200.0f, 200.0f));

        if(caminhoTextura) {
            text = new sf::Texture();
            // carrega a textura do corpo do arquivo
            std::cout << text->loadFromFile(caminhoTextura) << std::endl;
            // como a textura vai ser desenhada no corpo
            corpo.setTexture(text);
        }
    }

    Personagem::~Personagem() {
        if(text)
            delete text;
    }

    void Personagem::atualizar() {
        x += 0.008;
        y += 0.006;

        corpo.setPosition(sf::Vector2f(x, y));
    }

    void Personagem::desenhar(sf::RenderWindow *janela) {
        sf::Texture tex;
        tex.loadFromFile("TheUndying.png");
        corpo.setTexture(&tex);

        janela->draw(corpo);
    }
}
