#include "GerenciadorColisoes.h"
using namespace gerenciadores;

GerenciadorColisoes::GerenciadorColisoes()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::adicionarObstaculo(Obstaculo *obstaculo)
{
    // emplace adiciona o elemento no começo da lista
    obstaculos.emplace_front(obstaculo);
}

Obstaculo *GerenciadorColisoes::getObstaculo()
{
    return obstaculos.front();
    ;
}

bool GerenciadorColisoes::estaoColidindo(Entidade *p1, Entidade *p2)
{
}

void GerenciadorColisoes::verificarColisoes(RenderWindow &janela, Jogador *jogador)
{
    if (jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela.getSize().y)
        {
            jogador->resetVelocidadeY();
            jogador->setPosition(jogador->getGlobalBounds().left,
                                 janela.getSize().y - jogador->getGlobalBounds().height);
        }
    Obstaculo obst;
    // auto pega o tipo da variável que está recebendo
    for (auto &obst : obstaculos)
    {
        FloatRect jogadorLimites = jogador->getGlobalBounds();
        FloatRect obstaculoLimites = obst->getGlobalBounds();
        // proxPosicao vai pegar a proxima posicao do elemento antes dele se mexer
        proxPosicao = jogadorLimites;
        proxPosicao.left += jogador->getVelocidade().x;
        proxPosicao.top += jogador->getVelocidade().y;

        if (obstaculoLimites.intersects(proxPosicao))
        {
            // Colisão direita
            if (jogadorLimites.left < obstaculoLimites.left
                && jogadorLimites.left + jogadorLimites.width < obstaculoLimites.left + obstaculoLimites.width
                && jogadorLimites.top < obstaculoLimites.top + obstaculoLimites.height
                && jogadorLimites.top + jogadorLimites.height > obstaculoLimites.top)
            {
                jogador->resetVelocidadeY();
                jogador->setPosition(jogadorLimites.left - jogadorLimites.width, janela.getSize().y - jogador->getGlobalBounds().height);
            }

            // Colisao esquerda
            else if (jogadorLimites.left > obstaculoLimites.left && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left + obstaculoLimites.width && jogadorLimites.top < obstaculoLimites.top + obstaculoLimites.height && jogadorLimites.top + jogadorLimites.height > obstaculoLimites.top)
            {
                jogador->resetVelocidadeY();
                jogador->setPosition(jogadorLimites.left + jogadorLimites.width, janela.getSize().y - jogador->getGlobalBounds().height);
            }

            // Colisao em cima
            if (jogadorLimites.top > obstaculoLimites.top
                && jogadorLimites.top + jogadorLimites.height > obstaculoLimites.top + obstaculoLimites.height
                // && jogadorLimites.left < obstaculoLimites.left + obstaculoLimites.width
                && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left)
            {
                jogador->resetVelocidadeX();
                jogador->setPosition(jogadorLimites.left, obstaculoLimites.top + obstaculoLimites.height);
            }

            // Colisao embaixo
            else if (jogadorLimites.top < obstaculoLimites.top
                && jogadorLimites.top + jogadorLimites.height < obstaculoLimites.top + obstaculoLimites.height && jogadorLimites.left < obstaculoLimites.left + obstaculoLimites.width && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left)
            {
                jogador->resetVelocidadeX();
                jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height);
            }
        }
    }
}
