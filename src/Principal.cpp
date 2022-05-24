#include "Principal.h"

namespace entidades {
    Principal::Principal() : terminar(false), janela(new sf::RenderWindow(sf::VideoMode(800, 600), "Teste 1")) {
        listaAmigos.inserir(new Personagem(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(20, 20), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(30, 0), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(35, 15), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(sf::Vector2f(800.0f, 600.0f), sf::Vector2f(10, 40), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(sf::Vector2f(400.0f, 0.0f), sf::Vector2f(5, 5), "/Users/suzanabrasil/game/src/coelho.png"));
    }

    Principal::~Principal() {
        delete janela;

        listaAmigos.destruirPersonagens();
    }

    int Principal::executar() {
        relogio.restart();

        sf::Event e;

        while(!terminar) {
            if(janela->pollEvent(e)) {
                if(e.type == sf::Event::Closed) {
                    terminar = true;
                }
            }

            sf::Time t = relogio.getElapsedTime();
            janela->clear();
            listaAmigos.atualizarPersonagens(t.asSeconds());
            listaAmigos.desenharPersonagens(janela);
            janela->display();
        }
        relogio.restart();
        return 0;
    }
}
