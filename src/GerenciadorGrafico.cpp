#include "GerenciadorGrafico.h"
using namespace gerenciadores;

GerenciadorGrafico::GerenciadorGrafico() : camera(Vector2f(600, 350), Vector2f(1200,700))  {
}

GerenciadorGrafico::~GerenciadorGrafico() {}

void GerenciadorGrafico::inicializarJanela() {
    janela.create(sf::VideoMode(1200, 700), "Jogo", sf::Style::Close | sf::Style::Titlebar);
    janela.setView(camera);
    // limita a taxa de atualização da tela
    janela.setFramerateLimit(60);
}

RenderWindow* GerenciadorGrafico::getJanela() {
    return &janela;
}

View* GerenciadorGrafico::getView() {
    return &camera;
}

void GerenciadorGrafico::centralizar(const Vector2f centro) {
    camera.setCenter(Vector2f(centro.x, 350));
    janela.setView(camera);
}

void GerenciadorGrafico::resetCamera() {
    camera.setCenter(Vector2f(600, 350));
    janela.setView(camera);
}

void GerenciadorGrafico::desenhar(RectangleShape* background, Texture* text) {
    background->setSize(Vector2f(1200, 700));
    background->setTexture(text);
}
