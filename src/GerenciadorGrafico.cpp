#include "GerenciadorGrafico.h"
using namespace gerenciadores;

GerenciadorGrafico::GerenciadorGrafico() :
janela(new sf::RenderWindow(sf::VideoMode(1280, 720), "Jogo", sf::Style::Close | sf::Style::Titlebar))
{
    janela->setFramerateLimit(60);
}

GerenciadorGrafico::~GerenciadorGrafico() {
    delete janela;
}

void GerenciadorGrafico::mostrar() const {
    janela->display();
}

void GerenciadorGrafico::desenhar(const string caminhoText) {
    Texture* text;
    text->loadFromFile(caminhoText);
    Sprite sprite;
    sprite.setTexture(*text);
    janela->draw(sprite);
}

RenderWindow* GerenciadorGrafico::getJanela() const {
    return janela;
}
