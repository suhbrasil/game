#include "Personagem.h"
#include <math.h>
using namespace personagens;
using namespace std;

Personagem::Personagem(Vector2f pos, Vector2f v) : Entidade(), posicao(pos), velocidade(v) {
    id = 14;
}

Personagem::~Personagem() {

}

void Personagem::inicializarFenomenosFisicos() {
    velocidadeMaxima = 5.f;
    velocidadeMinima = 1.f;
    aceleracao = 3.f;
    atrito  = 0.9f;
    gravidade = 1.f;
    velocidadeMaximaY  = 35.f;
    velocidadeMinimaY = 1.f;
    alturaPulo = 300.f;
}

void Personagem::atualizarFenomenosFisicos() {
    velocidade.y += 1.f * gravidade;

   if(abs(velocidade.y) > velocidadeMaximaY) {
        if(velocidade.y < 0)
            velocidade.y = velocidadeMaximaY * -1.f;
        else if(velocidade.y > 0)
            velocidade.y  = velocidadeMaximaY;
    }

    velocidade.x *= atrito;
    if(abs(velocidade.x) < velocidadeMinima) {
        velocidade.x = 0.0f;
    }

    if(abs(velocidade.y) < velocidadeMinima){
        velocidade.y = 0.0f;
    }

    desenhavel.move(velocidade);
}

void Personagem::resetVelocidadeY() {
    velocidade.y = 0.f;
}

void Personagem::resetVelocidadeX() {
    velocidade.x = 0.f;
}

void Personagem::inverterVelocidade() {
    velocidade.x = -1.f * velocidade.x;
}
