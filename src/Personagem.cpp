#include "Personagem.h"
using namespace personagens;

Personagem::Personagem(Vector2f pos, Vector2f v) : Entidade(), posicao(pos), velocidade(v) {

}

Personagem::~Personagem() {

}

void Personagem::atualizar(float tempo) {
    posicao += velocidade*tempo;
}
