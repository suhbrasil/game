#include "Inimigo.h"
using namespace personagens;

Inimigo::Inimigo(Vector2f pos, Vector2f v) : Personagem(pos, v) {

}

Inimigo::~Inimigo() {}

void Inimigo::inicializarTextura() {
    // if(!textura.loadFromFile(caminhoText))
    //     printf("imagem não encontrada");
    if (!textura.loadFromFile("texture/rainha_ma.png"))
    {
        printf("imagem não encontrada");
    }
}
