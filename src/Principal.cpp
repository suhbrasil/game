#include "Principal.h"

namespace exercicio {
    Principal::Principal() {
        // VideoMode é o tamanho da tela
        janela = new sf::RenderWindow(sf::VideoMode(800, 600), "exercicio 1");
        amigo = Personagem(0, 0, "Users/suzanabrasil/jogo/src/TheUndying.png");
    }

    Principal::~Principal() {
        delete janela;
    }

    int Principal::executar() {
        while(true) {
            janela->clear();
            amigo.atualizar();
            // método desenhar vai colocar na janela a textura do personagem
            amigo.desenhar(janela);
            janela->display();
        }
        return 0;
    }
}
