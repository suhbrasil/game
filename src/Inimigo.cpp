#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(Vector2f pos, Vector2f v) : Personagem(pos, v) {

}

Inimigo::~Inimigo() {}

void Inimigo::inicializarTextura(const char* caminhoText) {
    textura.loadFromFile(caminhoText);
}
