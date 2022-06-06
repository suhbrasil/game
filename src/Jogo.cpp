#include "Jogo.h"

Jogo::Jogo()
{
    gerenciadorGrafico.inicializarJanela();
    inicializarJogador();
    gerenciadorGrafico.inicializarFundoTela();
}

Jogo::~Jogo()
{
    delete jogador;
}

void Jogo::inicializarJogador()
{
    jogador = new Jogador();
}

void Jogo::atualizarJogador()
{
    jogador->atualizar();
}

void Jogo::atualizar()
{
    while (gerenciadorGrafico.getJanela().pollEvent(event))
    {
        if (event.type == Event::Closed)
            gerenciadorGrafico.getJanela().close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            gerenciadorGrafico.getJanela().close();

        if(event.type ==  Event::KeyReleased &&
            (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Up ||
                 event.key.code == Keyboard::Down || event.key.code == Keyboard::Left
                    || event.key.code == Keyboard::Right))

            jogador->resetTimerAnimacao();
    }

    atualizarJogador();
    atualizarColisao();
}

void Jogo::atualizarRenderJogador() {
    jogador->render(gerenciadorGrafico.getJanela());
}

void Jogo::atualizarColisao() {

    if(jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > gerenciadorGrafico.getJanela().getSize().y) {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                gerenciadorGrafico.getJanela().getSize().y - jogador->getGlobalBounds().height);
    }
}

void Jogo::render()
{
    // Desenhar fundo de tela
    gerenciadorGrafico.renderFundoTela();

    // janela.clear(Color::Black);
    atualizarRenderJogador();
    gerenciadorGrafico.getJanela().display();
    // menu.executar();
}

void Jogo::executar()
{
    while (gerenciadorGrafico.getJanela().isOpen())
    {
        atualizar();
        render();
    }
}
