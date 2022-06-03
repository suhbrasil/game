#include "Jogador.h"
#include <iostream>
using namespace entidades;
using namespace sf;

#define ESTADOINICIAL 0
#define PULO 1
#define SEGUNDOESTADO 2

Jogador::Jogador()
{
    inicializarVariaveis();
    inicializarTextura();
    inicializarDesenhavel();
    inicializarAnimacao();
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
    movimentar();
    atualizarAnimacao();
    // std::cout << "Frame: " << countFrame << std::endl;
}

void Jogador::render(RenderTarget &target)
{
    target.draw(desenhavel);
}
void Jogador::inicializarTextura()
{
    if (!textura.loadFromFile("/Users/suzanabrasil/jogo/src/coelho.png"))
    {
        printf("imagem não encontrada");
    }
}

void Jogador::inicializarDesenhavel()
{
    desenhavel.setTexture(textura);
    frameAtual = IntRect(0, 0, 45, 34);
    desenhavel.setTextureRect(frameAtual);
    // pra mudar o tamanho do desenho
    desenhavel.setScale(2.0f, 2.0f);
}

void Jogador::inicializarVariaveis()
{
    countFrame = 0;
    movimentando = false;
    estadoDeAnimacao = ESTADOINICIAL;
}

void Jogador::inicializarAnimacao()
{
    timerAnimacao.restart();
}

void Jogador::atualizarAnimacao()
{
    if (timerAnimacao.getElapsedTime().asSeconds() >= 0.2f)
    {
        if (!movimentando)
        {
            // movimenta a textura pra esquerda
            frameAtual.left += 273.3f;
            if (frameAtual.left >= 273.f)
                frameAtual.left = 0;
        }
        else if(movimentando && countFrame > 40){
            if(estadoDeAnimacao == ESTADOINICIAL) {
                frameAtual = IntRect(46, 0, 47, 34);
            }
            else if(estadoDeAnimacao == SEGUNDOESTADO) {
                frameAtual = IntRect(0, 0, 45, 34);
            }
            countFrame = 0;
        }
    }
    desenhavel.setTextureRect(frameAtual);
}

void Jogador::movimentar()
{
    movimentando = false;
    if (Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        desenhavel.move(-0.5f, 0.f);
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        desenhavel.move(0.5f, 0.f);
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        desenhavel.move(0.f, 0.5f);
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        desenhavel.move(0.f, -0.5f);
        movimentando = true;
    }

    countFrame++;

    if(estadoDeAnimacao == ESTADOINICIAL)
        estadoDeAnimacao = SEGUNDOESTADO;
    else
        estadoDeAnimacao = ESTADOINICIAL;
}
