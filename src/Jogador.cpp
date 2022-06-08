#include "Jogador.h"
#include <iostream>
using namespace personagens;
using namespace sf;

Jogador::Jogador() : Personagem()
{
    inicializarVariaveis();
    inicializarTextura();
    inicializarDesenhavel();
    inicializarAnimacao();
    inicializarFenomenosFisicos();

    desenhavel.setPosition(posicaoInicialX,posicaoInicialY);

}

Jogador::~Jogador()
{
}

void Entidade::inicializarTextura()
{
    if (!textura.loadFromFile("textura/coelho.png"))
    {
        printf("imagem não encontrada");
    }
}
void Jogador::atualizar()
{
    atualizarMovimentacao();
    atualizarAnimacao();
    atualizarFenomenosFisicos();
}

void Jogador::inicializarVariaveis()
{
    countFrame = 0;
    movimentando = false;
    estadoDeAnimacao = ESTADOINICIAL;
    podePular = true;
    posicaoInicialX = 0.f;
    posicaoInicialY = 632.f;
}



void Jogador::atualizarMovimentacao()
{
    movimentando = false;
    if (Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        movimentar(-0.5f, 0.f);
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        movimentar(0.5f, 0.f);
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && podePular)
    {
        velocidade.y = -sqrtf(2.f * gravidade * alturaPulo);
        movimentando = true;
        estadoDeAnimacao = PULO;
    }

    if(abs(desenhavel.getPosition().y - posicaoInicialY) < alturaPulo) podePular = true;
    else podePular = false;




    countFrame++;

    if(estadoDeAnimacao == ESTADOINICIAL)
        estadoDeAnimacao = SEGUNDOESTADO;
    else
        estadoDeAnimacao = ESTADOINICIAL;
}

void Jogador::inicializarFenomenosFisicos() {

    velocidadeMaxima = 5.f;
    velocidadeMinima = 1.f;
    aceleracao = 3.f;
    atrito  = 0.9f;
    gravidade = 2.f;
    velocidadeMaximaY  = 5.f;
    velocidadeMinimaY = 1.f;
    alturaPulo = 100.f;
}

void Jogador::movimentar(const float direcaoX, const float direcaoY) {

    velocidade.x += direcaoX * aceleracao;
    velocidade.y += direcaoY * aceleracao;

    if(abs(velocidade.x) > velocidadeMaxima) {
        if(velocidade.x < 0) velocidade.x = velocidadeMaxima * -1.f;
        else if(velocidade.x > 0) velocidade.x  = velocidadeMaxima;
    }
}

void Jogador::atualizarFenomenosFisicos() {

    velocidade.y += 1.f * gravidade;

   if(abs(velocidade.y) > velocidadeMaximaY) {
        if(velocidade.y < 0) velocidade.y = velocidadeMaximaY * -1.f;
        else if(velocidade.y > 0) velocidade.y  = velocidadeMaximaY;
    }

    velocidade.x  *= atrito;
    if(abs(velocidade.x) < velocidadeMinima) {
        velocidade.x = 0.0f;
    }

    if(abs(velocidade.y) <velocidadeMinima){
        velocidade.y = 0.0f;
    }

    desenhavel.move(velocidade);


}

void Jogador::resetVelocidadeY() {

    velocidade.y = 0.f;

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
        else if(movimentando && countFrame > 20){
            if(estadoDeAnimacao == ESTADOINICIAL) {

                 frameAtual = IntRect(0, 0, 45, 34);
            }
            else if(estadoDeAnimacao == SEGUNDOESTADO) {
               frameAtual = IntRect(46, 0, 47, 34);
            }
            else if(estadoDeAnimacao == PULO){
                frameAtual = IntRect(96,0,45,34);
            }
            countFrame = 0;
        }
    }
    desenhavel.setTextureRect(frameAtual);
}
