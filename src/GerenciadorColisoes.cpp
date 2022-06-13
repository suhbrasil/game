#include "GerenciadorColisoes.h"
using namespace gerenciadores;

GerenciadorColisoes::GerenciadorColisoes() : contar(1)
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

void GerenciadorColisoes::adicionarProjetil(Projetil *projetil)
{
    // emplace adiciona o elemento no começo da lista
    projeteis.push_back(projetil);
}

Obstaculo *GerenciadorColisoes::getObstaculo()
{
    return obstaculos.front();
}

void GerenciadorColisoes::adicionarInimigo(Inimigo *inimigo)
{
    // emplace adiciona o elemento no começo da lista
    inimigos.push_back(inimigo);
}

Inimigo *GerenciadorColisoes::getInimigo()
{
    return inimigos.back();
}
bool GerenciadorColisoes::colisaoDireita(FloatRect entidade1, FloatRect entidade2)
{

    if (entidade1.left < entidade2.left && entidade1.left + entidade1.width < entidade2.left + entidade2.width && entidade1.top < entidade2.top + entidade2.height && entidade1.top + entidade1.height > entidade2.top)

        return true;

    return false;
}
bool GerenciadorColisoes::colisaoEsquerda(FloatRect entidade1, FloatRect entidade2)
{

    if (entidade1.left > entidade2.left && entidade1.left + entidade1.width > entidade2.left + entidade2.width && entidade1.top < entidade2.top + entidade2.height && entidade1.top + entidade1.height > entidade2.top)

        return true;

    return false;
}
bool GerenciadorColisoes::colisaoInferior(FloatRect entidade1, FloatRect entidade2)
{
    if (entidade1.top > entidade2.top && entidade1.top + entidade1.height > entidade2.top + entidade2.height && entidade1.left < entidade2.left + entidade2.width && entidade1.left + entidade1.width > entidade2.left)

        return true;

    return false;
}
bool GerenciadorColisoes::colisaoSuperior(FloatRect entidade1, FloatRect entidade2)
{

    if (entidade1.top < entidade2.top && entidade1.top + entidade1.height < entidade2.top + entidade2.height && entidade1.left < entidade2.left + entidade2.width && entidade1.left + entidade1.width > entidade2.left)

        return true;

    return false;
}
void GerenciadorColisoes::verificarColisaoJogadorInimigo(Jogador *jogador)
{
    Inimigo inimigo;
    // auto pega o tipo da variável que está recebendo
    for (auto &inimigo : inimigos)
    {
        FloatRect jogadorLimites = jogador->getGlobalBounds();
        FloatRect inimigoLimites = inimigo->getGlobalBounds();
        // proxPosicao vai pegar a proxima posicao do elemento antes dele se mexer
        proxPosicao = jogadorLimites;
        proxPosicao.left += jogador->getVelocidade().x;
        proxPosicao.top += jogador->getVelocidade().y;

        if (inimigoLimites.intersects(proxPosicao))
        {
            if (colisaoDireita(jogadorLimites, inimigoLimites))
            {
                inimigo->inverterVelocidade();
                jogador->inverterVelocidade();
                jogador->setPosition(inimigo->getPosition().x - jogadorLimites.width, jogador->getPosition().y);
                jogador->diminuirPontos();
            }

            else if (colisaoEsquerda(jogadorLimites, inimigoLimites))
            {
                inimigo->inverterVelocidade();
                jogador->inverterVelocidade();
                jogador->setPosition(inimigo->getPosition().x + inimigoLimites.width, jogador->getPosition().y);
                jogador->diminuirPontos();
            }

            if (colisaoInferior(jogadorLimites, inimigoLimites))
            {
                jogador->setPosition(jogadorLimites.left, inimigoLimites.top + inimigoLimites.height);
            }

            else if (colisaoSuperior(jogadorLimites, inimigoLimites))
            {
                inimigo->desenhavel.move(0.0f, -1000.f);
                jogador->setPodePular(true);
                jogador->setPosition(jogadorLimites.left, inimigoLimites.top - inimigoLimites.height);
                jogador->ganharPontos();
            }
        }
    }
}

void GerenciadorColisoes::verificarColisaoJogadorObstaculo(Jogador *jogador)
{

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
            if (colisaoDireita(jogadorLimites, obstaculoLimites))
            {
                jogador->resetVelocidadeY();
                jogador->setPosition(obst->getPosition().x - jogadorLimites.width, jogador->getPosition().y);
            }

            else if (colisaoEsquerda(jogadorLimites, obstaculoLimites))
            {
                jogador->resetVelocidadeY();
                jogador->setPosition(obst->getPosition().x + obstaculoLimites.width, jogador->getPosition().y);
            }

            if (colisaoInferior(jogadorLimites, obstaculoLimites))
            {
                jogador->resetVelocidadeX();
                jogador->setPosition(jogadorLimites.left, obstaculoLimites.top + obstaculoLimites.height);
            }

            else if (colisaoSuperior(jogadorLimites, obstaculoLimites))
            {
                jogador->setPodePular(true);
                // Plataforma (galho)
                if (obst->getId() == 8)
                {
                    jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height);
                }
                // Espinho
                else if (obst->getId() == 4)
                {
                    jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height + 40.f);
                    if (contar)
                    {
                        jogador->diminuirPontos();
                        contar = 0;
                    }
                }
                else
                {
                    jogador->setPosition(jogadorLimites.left, obstaculoLimites.top - obstaculoLimites.height + 40.f);
                }
            }
        }
    }
}

void GerenciadorColisoes::verificarColisaoObstaculoInimigo()
{

    Obstaculo obst;
    Inimigo inimigo;
    // auto pega o tipo da variável que está recebendo
    for (auto &obst : obstaculos)
    {
        for (auto &inimigo : inimigos)
        {
            FloatRect inimigoLimites = inimigo->getGlobalBounds();
            FloatRect obstaculoLimites = obst->getGlobalBounds();
            // proxPosicao vai pegar a proxima posicao do elemento antes dele se mexer
            proxPosicao = inimigoLimites;
            proxPosicao.left += inimigo->getVelocidade().x;
            proxPosicao.top += inimigo->getVelocidade().y;

            if (inimigo->getId() != 16)
            {
                if (obstaculoLimites.intersects(proxPosicao))
                {
                    if (colisaoDireita(inimigoLimites, obstaculoLimites))
                    {
                        inimigo->inverterVelocidade();
                        inimigo->setPosition(obst->getPosition().x - inimigoLimites.width, inimigo->getPosition().y);
                    }

                    else if (colisaoEsquerda(inimigoLimites, obstaculoLimites))
                    {
                        inimigo->inverterVelocidade();
                        inimigo->setPosition(obst->getPosition().x + obstaculoLimites.width, inimigo->getPosition().y);
                    }

                    if (colisaoInferior(inimigoLimites, obstaculoLimites))
                    {
                        inimigo->inverterVelocidade();
                        inimigo->setPosition(inimigoLimites.left, obstaculoLimites.top + obstaculoLimites.height);
                    }

                    else if (colisaoSuperior(inimigoLimites, obstaculoLimites))
                    {
                        // Plataforma (galho)
                        if (obst->getId() == 8)
                        {
                            inimigo->setPosition(inimigoLimites.left, obstaculoLimites.top - obstaculoLimites.height);
                        }
                        // Espinho
                        else if (obst->getId() == 4)
                        {
                            inimigo->setPosition(inimigoLimites.left, obstaculoLimites.top - obstaculoLimites.height + 95.f);
                        }
                        else
                        {
                            inimigo->setPosition(inimigoLimites.left, obstaculoLimites.top - obstaculoLimites.height + 40.f);
                        }
                    }
                }
            }
        }
    }
}

void GerenciadorColisoes::verificarColisaoInimigoInimigo()
{

    // auto pega o tipo da variável que está recebendo
    for (auto &inimigo2 : inimigos)
    {
        for (auto &inimigo : inimigos)
        {
            FloatRect inimigo1Limites = inimigo->getGlobalBounds();
            FloatRect inimigo2Limites = inimigo2->getGlobalBounds();
            // proxPosicao vai pegar a proxima posicao do elemento antes dele se mexer
            proxPosicao = inimigo1Limites;
            proxPosicao.left += inimigo->getVelocidade().x;
            proxPosicao.top += inimigo->getVelocidade().y;

            if (inimigo2Limites.intersects(proxPosicao))
            {
                if (colisaoDireita(inimigo1Limites, inimigo2Limites))
                {
                    inimigo->inverterVelocidade();
                    inimigo->setPosition(inimigo2->getPosition().x - inimigo1Limites.width, inimigo->getPosition().y);
                }

                else if (colisaoEsquerda(inimigo1Limites, inimigo2Limites))
                {
                    inimigo->inverterVelocidade();
                    inimigo->setPosition(inimigo2->getPosition().x + inimigo2Limites.width, inimigo->getPosition().y);
                }

                if (colisaoInferior(inimigo1Limites, inimigo2Limites))
                {
                    inimigo->resetVelocidadeX();
                    inimigo->setPosition(inimigo1Limites.left, inimigo2Limites.top + inimigo2Limites.height);
                }

                else if (colisaoSuperior(inimigo1Limites, inimigo2Limites))
                {
                    if (inimigo2->getId() == 8)
                    {
                        inimigo->setPosition(inimigo1Limites.left, inimigo2Limites.top - inimigo1Limites.height);
                    }
                    // Espinho
                    else if (inimigo2->getId() == 4)
                    {
                        inimigo->setPosition(inimigo1Limites.left, inimigo2Limites.top - inimigo1Limites.height + 95.f);
                    }
                    else
                    {
                        inimigo->setPosition(inimigo1Limites.left, inimigo2Limites.top - inimigo1Limites.height + 40.f);
                    }
                }
            }
        }
    }
}

void GerenciadorColisoes::verificarColisaoProjetilJogador(Jogador *jogador)
{

    Projetil projetil;
    // auto pega o tipo da variável que está recebendo
    for (auto &projetil : projeteis)
    {
        FloatRect jogadorLimites = jogador->getGlobalBounds();
        FloatRect projetilLimites = projetil->shape.getGlobalBounds();

        // proxPosicao vai pegar a proxima posicao do elemento antes dele se mexer
        proxPosicao = jogadorLimites;
        proxPosicao.left += jogador->getVelocidade().x;
        proxPosicao.top += jogador->getVelocidade().y;

        if (projetilLimites.intersects(proxPosicao))
        {
            if (colisaoDireita(jogadorLimites, projetilLimites))
            {
                projetil->shape.move(0.0f, 1000.f);
                jogador->setPosition(projetil->shape.getPosition().x - jogadorLimites.width, jogador->getPosition().y);
            }

            else if (colisaoEsquerda(jogadorLimites, projetilLimites))
            {
                projetil->shape.move(0.0f, 1000.f);
                jogador->setPosition(projetil->shape.getPosition().x + projetilLimites.width, jogador->getPosition().y);
            }

            if (colisaoInferior(jogadorLimites, projetilLimites))
            {
                projetil->shape.move(0.0f, 1000.f);
                jogador->setPosition(jogadorLimites.left, projetilLimites.top + projetilLimites.height);
            }

            else if (colisaoSuperior(jogadorLimites, projetilLimites))
            {
                projetil->shape.move(0.f, 1000.f);
                jogador->setPosition(jogadorLimites.left, projetilLimites.top - projetilLimites.height);
            }
        }
    }
}

void GerenciadorColisoes::verificarColisaoChaoJogador(RenderWindow &janela, Jogador *jogador)
{
    if (jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela.getSize().y)
    {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                             janela.getSize().y - jogador->getGlobalBounds().height);
        jogador->setPodePular(true);
        contar = 1;
    }
}

void GerenciadorColisoes::verificarColisaoChaoInimigo(RenderWindow &janela)
{
    Inimigo inimigo;
    for (auto &inimigo : inimigos)
    {
        if (inimigo->getGlobalBounds().top + inimigo->getGlobalBounds().height > janela.getSize().y)
        {
            inimigo->resetVelocidadeY();
            inimigo->setPosition(inimigo->getGlobalBounds().left,
                                 janela.getSize().y - inimigo->getGlobalBounds().height);
        }
    }
}

void GerenciadorColisoes::verificarColisaoInicioTelaJogador(Jogador *jogador)
{
    if (jogador->getPosition().x <= 0)
        jogador->setPosition(0, jogador->getPosition().y);
}

void GerenciadorColisoes::verificarColisaoInicioTelaRainha(Inimigo *inimigo)
{
    if (inimigo->getId() == 16 && inimigo->getPosition().x <= 0)
        inimigo->inverterVelocidade();
}

void GerenciadorColisoes::verificarColisoes(RenderWindow &janela, Jogador *jogador)
{
    verificarColisaoChaoJogador(janela, jogador);
    verificarColisaoChaoInimigo(janela);
    verificarColisaoJogadorInimigo(jogador);
    verificarColisaoJogadorObstaculo(jogador);
    verificarColisaoObstaculoInimigo();
    verificarColisaoInimigoInimigo();
    verificarColisaoProjetilJogador(jogador);
}
