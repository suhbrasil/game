#include "Jogo.h"

Jogo::Jogo()
{
    inicializarJanela();
    inicializarJogador();
    inicializarFundoTela();
}

Jogo::~Jogo()
{
    delete jogador;
}

void Jogo::inicializarJanela()
{
    janela.create(sf::VideoMode(1400, 700), "Jogo", sf::Style::Close | sf::Style::Titlebar);
    // limita a taxa de atualização da tela
    janela.setFramerateLimit(60);
}

const RenderWindow& Jogo::getJanela() const
{
    return janela;
}

void Jogo::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("/Users/suzanabrasil/jogo/textura/background.jpeg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void Jogo::renderFundoTela() {
    janela.draw(fundoTela);
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

void Jogo::atualizarRenderJogador() {
    jogador->render(janela);
}

void Jogo::atualizarColisao() {

    if(jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela.getSize().y) {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                janela.getSize().y - jogador->getGlobalBounds().height);
    }
}

void Jogo::render()
{
    // Desenhar fundo de tela
    renderFundoTela();

    // janela.clear(Color::Black);
    atualizarRenderJogador();
    janela.display();
    // menu.executar();
}

void Jogo::executar()
{
    while (janela.isOpen())
    {
        atualizar();
        render();
    }
}
