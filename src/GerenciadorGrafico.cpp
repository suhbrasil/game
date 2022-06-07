#include "GerenciadorGrafico.h"
using namespace gerenciadores;

GerenciadorGrafico::GerenciadorGrafico() {}

GerenciadorGrafico::~GerenciadorGrafico() {}

void GerenciadorGrafico::inicializarJanela() {
    janela.create(sf::VideoMode(1200, 700), "Jogo", sf::Style::Close | sf::Style::Titlebar);
    // limita a taxa de atualização da tela
    janela.setFramerateLimit(60);
}

RenderWindow& GerenciadorGrafico::getJanela() {
    return janela;
}

void GerenciadorGrafico::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("/Users/suzanabrasil/jogo/textura/background.jpeg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void GerenciadorGrafico::renderFundoTela() {
    janela.draw(fundoTela);
}

void GerenciadorGrafico::inserir(Ente* elem) {
    pilha.push(elem);
}

Ente* GerenciadorGrafico::recuperar() {
    if(pilha.empty())
        cout << "Nenhum elemento" << endl;
    Ente* elem = pilha.top();
    pilha.pop();
    return elem;
}
