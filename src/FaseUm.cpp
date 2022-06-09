#include "FaseUm.h"
using namespace fases;

FaseUm::FaseUm(Jogador* j) : Fase(j)
{
    inicializarJogador(j);
    inicializarObstaculo();
    inicializarFundoTela();
}

FaseUm::~FaseUm()
{
    delete obstaculo;
}

void FaseUm::inicializarJanela()
{
    janela.create(sf::VideoMode(1200, 700), "FaseUm", sf::Style::Close | sf::Style::Titlebar);
    // limita a taxa de atualização da tela
    janela.setFramerateLimit(60);
}

const RenderWindow& FaseUm::getJanela() const
{
    return janela;
}

void FaseUm::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("texture/background.jpeg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void FaseUm::inicializarObstaculo() {
    obstaculo = new Obstaculo();
}

void FaseUm::renderFundoTela() {
    janela.draw(fundoTela);
}

void FaseUm::inicializarJogador(Jogador* j)
{
    jogador = j;
}


void FaseUm::atualizarJogador()
{
    jogador->atualizar();
}

void FaseUm::atualizar()
{

    while (janela.pollEvent(event))
    {
        if (event.type == Event::Closed)
            janela.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            janela.close();

        if(event.type ==  Event::KeyReleased &&
            (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Up ||
                 event.key.code == Keyboard::Down || event.key.code == Keyboard::Left
                    || event.key.code == Keyboard::Right))

            jogador->resetTimerAnimacao();
    }

    atualizarJogador();
    atualizarColisao();
}

void FaseUm::atualizarRenderJogador() {
    jogador->render(janela);
    obstaculo->render(janela);
}

void FaseUm::atualizarColisao() {

    if(jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela.getSize().y) {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                janela.getSize().y - jogador->getGlobalBounds().height);
    }
}

void FaseUm::render()
{
    // Desenhar fundo de tela
    renderFundoTela();
    atualizarRenderJogador();
    janela.display();
}

void FaseUm::executar()
{
    inicializarJanela();
    while (janela.isOpen())
    {
        janela.clear();
        atualizar();
        render();
    }
}
