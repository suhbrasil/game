#include "GerenciadorGrafico.h"
#include <iostream>

namespace entidades {
    GerenciadorGrafico::GerenciadorGrafico() :
    janela(new sf::RenderWindow(sf::VideoMode(1400, 800), "Testando")),
    camera(sf::Vector2f(400, 300), sf::Vector2f(1400, 800))
    {
        // Deixei comentado, pois não entendi muito bem o uso do setFramerateLimit
        // janela->setFramerateLimit(144);
        janela->setView(camera);
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        delete janela;
        for(auto i : texturas)
            delete i.second;
    }

    void GerenciadorGrafico::mostrar() const {
        janela->display();
    }

    void GerenciadorGrafico::limpar(int r, int g, int b) {
        janela->clear(sf::Color(r, g, b));
    }

    void GerenciadorGrafico::desenhar(const std::string caminho, const Vetor2F posicao) {
        if(texturas.count(caminho) == 0) {
            std::cout << "Imagem em " << caminho << " não carregada." << std::endl;
            exit(100);
        }

        sf::Texture* text = texturas[caminho];
        sf::Sprite sprite;
        sprite.setTexture(*text);
        sprite.setPosition(posicao.x, posicao.y);
        janela->draw(sprite);
    }

    bool GerenciadorGrafico::carregarTextura(const std::string caminho) {
        if(texturas.count(caminho) == 1)
            return true;
        else {
            sf::Texture* text = new sf::Texture();

            if(!text->loadFromFile(caminho)) {
                std::cout << "Imagem em " << caminho << "não encontrada!" << std::endl;
                exit(101);
            }

            texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
            // texturas.emplace(caminho, text);
            return true;
        }

    }

    void GerenciadorGrafico::centralizar(const Vetor2F centro) {
        camera.setCenter(sf::Vector2f(centro.x, centro.y));
    }

    sf::RenderWindow* GerenciadorGrafico::getJanela() const {
        return janela;
    }

    const Vetor2F GerenciadorGrafico::getTamanho(const std::string& caminho) const {
        if(texturas.count(caminho) == 0) {
            std::cout << "Imagem em " << caminho << " não carregada." << std::endl;
            exit(102);
        }

        sf::Vector2u dimensoes = (texturas.at(caminho))->getSize();
        return Vetor2F(dimensoes.x, dimensoes.y);
    }
}
