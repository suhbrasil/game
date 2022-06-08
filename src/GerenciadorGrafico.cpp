#include "GerenciadorGrafico.h"
using namespace gerenciadores;

GerenciadorGrafico::GerenciadorGrafico() {}

GerenciadorGrafico::~GerenciadorGrafico() {}

void GerenciadorGrafico::inicializarJanela() {
    janela.create(sf::VideoMode(1280, 720), "Jogo", sf::Style::Close | sf::Style::Titlebar);
    // limita a taxa de atualização da tela
    janela.setFramerateLimit(60);
}

RenderWindow& GerenciadorGrafico::getJanela() {
    return janela;
}

void GerenciadorGrafico::desenhar(RectangleShape* background, Texture* text) {
    background->setSize(Vector2f(1280, 720));
    background->setTexture(text);
}
