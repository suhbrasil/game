#include "JogadorUm.h"
#include <iostream>
using namespace personagens;
using namespace sf;

JogadorUm::JogadorUm() : Personagem()
{
    id = 17;

    inicializarVariaveis();
    inicializarTextura();
    inicializarDesenhavel();
    inicializarAnimacao();
    inicializarFenomenosFisicos();

    desenhavel.setPosition(posicaoInicialX,posicaoInicialY);
}

JogadorUm::~JogadorUm()
{
}

void JogadorUm::inicializarDesenhavel()
{
    desenhavel.setTexture(textura);

    frameAtual = IntRect(0, 0, 45, 34);
    desenhavel.setTextureRect(frameAtual);
    // pra mudar o tamanho do desenho
    desenhavel.setScale(2.0f, 2.0f);
}

void JogadorUm::inicializarTextura()
{
    if (!textura.loadFromFile("texture/coelho.png"))
    {
        printf("imagem não encontrada");
    }
}
void JogadorUm::atualizar()
{
    atualizarMovimentacao();
    atualizarAnimacao();
    atualizarFenomenosFisicos();
}

void JogadorUm::inicializarVariaveis()
{
    countFrame = 0;
    movimentando = false;
    estadoDeAnimacao = ESTADOINICIAL;
    podePular = true;
    pontos = 700;
    fstream pos ("jogada.txt");
    if(pos.is_open()) {
        string linhaPosX;
        pos >> linhaPosX;
        posicaoInicialX = std::stof(linhaPosX);
        string linhaPosY;
        pos >> linhaPosY;
        posicaoInicialY = std::stof(linhaPosX);
        pos.close();
        remove("jogada.txt");
    }
    else {
        posicaoInicialX = 0.f;
        posicaoInicialY = 637.f;
    }
}

void JogadorUm::atualizarMovimentacao()
{
    movimentando = false;

    if (Keyboard::isKeyPressed(sf::Keyboard::Key::J))
    {
        movimentar(-0.5f, 0.f);
        movimentando = true;
    }

    else if(Keyboard::isKeyPressed(sf::Keyboard::Key::L) && Keyboard::isKeyPressed(sf::Keyboard::Key::I) && podePular) {
        podePular = false;
        movimentar(2.f, -sqrtf(2.f * gravidade * alturaPulo));
        movimentando = true;
    }

    else if(Keyboard::isKeyPressed(sf::Keyboard::Key::J) && Keyboard::isKeyPressed(sf::Keyboard::Key::I) && podePular) {
        podePular = false;
        movimentar(-2.0f, -sqrtf(2.f * gravidade * alturaPulo));
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::L))
    {
        movimentar(0.5f, 0.f);
        movimentando = true;
    }

    else if (Keyboard::isKeyPressed(sf::Keyboard::Key::I) && podePular)
    {
        podePular = false;
        velocidade.y = -sqrtf(2.f * gravidade * alturaPulo);
        velocidade.y *= 10.f;
        movimentando = true;

    }

    velocidade.y += gravidade * 0.8;


    countFrame++;

    if(estadoDeAnimacao == ESTADOINICIAL)
        estadoDeAnimacao = SEGUNDOESTADO;
    else
        estadoDeAnimacao = ESTADOINICIAL;
}

void JogadorUm::movimentar(const float direcaoX, const float direcaoY) {
    velocidade.x += direcaoX * aceleracao;
    velocidade.y += direcaoY * aceleracao;

    if(abs(velocidade.x) > velocidadeMaxima) {
        if(velocidade.x < 0)
            velocidade.x = velocidadeMaxima * -1.f;
        else if(velocidade.x > 0)
            velocidade.x  = velocidadeMaxima;
    }
}

void JogadorUm::resetPosicao() {
    desenhavel.setPosition(0,632);
}

void JogadorUm::atualizarAnimacao()
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
                frameAtual = IntRect(0, 0, 40, 34);
            }
            else if(estadoDeAnimacao == SEGUNDOESTADO) {
                frameAtual = IntRect(46, 0, 47, 34);
            }
            else if(estadoDeAnimacao == PULO){
                frameAtual = IntRect(96,0,49,34);
            }
            countFrame = 0;
        }
    }
    desenhavel.setTextureRect(frameAtual);
}

Vector2f JogadorUm::getVelocidade() {
    return velocidade;
}

bool JogadorUm::getPodePular() {
    return podePular;
}

void JogadorUm::setPodePular(bool pular) {
    podePular = pular;
}

void JogadorUm::diminuirPontos() {
    pontos -= 10;
    cout << pontos << endl;
}

void JogadorUm::ganharPontos() {
    pontos += 10;
    cout << pontos << endl;
}

int JogadorUm::getPontos() {
    return pontos;
}
