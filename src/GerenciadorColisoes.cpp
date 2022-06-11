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
}

bool GerenciadorColisoes::estaoColidindo(Jogador *p1, Obstaculo *p2, float push)
{

    Vector2f posicao1 = p1->getPosition();
    Vector2f dimensoes1 = p1->getDimensoesMetade();

    Vector2f posicao2 = p2->getPosition();
    Vector2f dimensoes2 = p2->getDimensoesMetade();

    float deltaX = posicao1.x - posicao2.x;
    float deltaY = posicao1.y - posicao2.y;

    float intersecaoX = abs(deltaX) - (dimensoes1.x + dimensoes2.x);
    float intersecaoY = abs(deltaY) - (dimensoes1.y + dimensoes2.y);

    if (intersecaoX < 0.0f && intersecaoY < 0.0f)
    {
        push = min(max(push, 0.0f), 1.0f);

        if (intersecaoX > intersecaoY)
        {
            if (deltaX > 0.0f)
            {
                p1->desenhavel.move(intersecaoX * (1 - push), 0.0f);
                p2->desenhavel.move(-intersecaoX * push, 0.0f);
            }
            else
            {
                p1->desenhavel.move(-intersecaoX * (1 - push), 0.0f);
                p2->desenhavel.move(intersecaoX * push, 0.0f);
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                p1->desenhavel.move(0.0f, intersecaoY * (1 - push));
                p2->desenhavel.move(0.0f, -intersecaoY * push);
            }
            else
            {
                p1->desenhavel.move(0.0f, -intersecaoY * (1 - push));
                p2->desenhavel.move(0.0f, -intersecaoY * push);
            }
        }
        return true;
    }

    return false;
}

void GerenciadorColisoes::verificarColisoes(RenderWindow &janela, Jogador *jogador)
{
    // variavel para evitar de ficar diminuindo os pontos em loop enquanto o jogador estiver em cima do obstaculo
    int contar = 1;
    if (jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela.getSize().y)
    {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                             janela.getSize().y - jogador->getGlobalBounds().height);
        jogador->setPodePular(true);
    }
    else
        contar = 0;

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
                jogador->setPosition(obst->getPosition().x - jogadorLimites.width, jogador->getPosition().y);
            }

            // Colisao esquerda
            else if (jogadorLimites.left > obstaculoLimites.left
                && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left + obstaculoLimites.width
                && jogadorLimites.top < obstaculoLimites.top + obstaculoLimites.height
                && jogadorLimites.top + jogadorLimites.height > obstaculoLimites.top)
            {
                jogador->resetVelocidadeY();
                jogador->setPosition(obst->getPosition().x + obstaculoLimites.width, jogador->getPosition().y);
            }

            // Colisao embaixo
            if (jogadorLimites.top > obstaculoLimites.top
                && jogadorLimites.top + jogadorLimites.height > obstaculoLimites.top + obstaculoLimites.height
                && jogadorLimites.left < obstaculoLimites.left + obstaculoLimites.width
                && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left)
            {
                jogador->resetVelocidadeX();
                jogador->setPosition(jogadorLimites.left, obstaculoLimites.top + obstaculoLimites.height);
            }

            // Colisao em cima
            else if (jogadorLimites.top < obstaculoLimites.top
                && jogadorLimites.top + jogadorLimites.height < obstaculoLimites.top + obstaculoLimites.height
                && jogadorLimites.left < obstaculoLimites.left + obstaculoLimites.width
                && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left)
            {
                jogador->setPodePular(true);
                // Plataforma (galho)
                if(obst->getId() == 8) {
                    // cout << "Colidiu galho" << endl;
                    jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height);
                }
                // Espinho
                else if (obst->getId() == 4) {
                    // cout << "Colidiu espinho" << endl;
                    jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height + 95.f);
                    if((janela.getSize().y - obstaculoLimites.top - obstaculoLimites.height) <= 0 && contar)
                        jogador->diminuirPontos();
                }
                else {
                    jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height + 40.f);
                    if((janela.getSize().y - obstaculoLimites.top - obstaculoLimites.height) <= 0 && contar)
                        jogador->diminuirPontos();
                }

                // jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height);
                // if((janela.getSize().y - obstaculoLimites.top - obstaculoLimites.height) <= 0 && contar) {
                //
                // }
            }
        }
    }
}

bool GerenciadorColisoes::verificarColisaoEmBaixo(Jogador *j, Obstaculo *obs)
{

    FloatRect jogadorLimites = j->getGlobalBounds();
    FloatRect obstaculoLimites = obs->getGlobalBounds();

    if (jogadorLimites.top < obstaculoLimites.top && jogadorLimites.top + jogadorLimites.height < obstaculoLimites.top + obstaculoLimites.height && jogadorLimites.left < obstaculoLimites.left + obstaculoLimites.width && jogadorLimites.left + jogadorLimites.width > obstaculoLimites.left)

        return true;

    return false;
}
