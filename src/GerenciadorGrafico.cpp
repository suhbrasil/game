#include "GerenciadorGrafico.h"
#include <iostream>

namespace entidades {
    GerenciadorGrafico::GerenciadorGrafico() :
    janela(new sf::RenderWindow(sf::VideoMode(800, 600), "Testando")),
    camera(sf::Vector2f(400, 300), sf::Vector2f(400, 300))
    {
        janela->setView(camera);
    }

    GerenciadorGrafico::~GerenciadorGrafico() {
        delete janela;

        // para todos os elementos dentro do mapa deleta só o valor (cada elemento do mapa tem uma chave e um valor, i->second deleta só o valor)
        /*
        for(auto i = texturas.begin(); i != texturas.end(); ++i) {
            delete (*i)->second;
        }
        */
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

        // depois colocar algo aqui para verificar se a textura está completamente fora da câmera e não desenhá-la

        // Sprite é uma classe do sfml só para criar texturas (pode ser com RectangleShape também)
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
}
