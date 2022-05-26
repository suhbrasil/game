#include "Principal.h"

namespace entidades {
    Principal::Principal() : terminar(false) {
        listaAmigos.inserir(new Personagem(Vetor2F(0.0f, 0.0f), Vetor2F(0, 10), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(Vetor2F(0.0f, 300.0f), Vetor2F(5, 5), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(Vetor2F(200.0f, 200.0f), Vetor2F(10, 0), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(Vetor2F(800.0f, 600.0f), Vetor2F(0, 5), "/Users/suzanabrasil/game/src/coelho.png"));
        listaAmigos.inserir(new Personagem(Vetor2F(400.0f, 0.0f), Vetor2F(5, 5), "/Users/suzanabrasil/game/src/coelho.png"));

        listaAmigos.inicializarEntidades(gerenciadorGrafico, gerenciadorEventos);
    }

    Principal::~Principal() {
        listaAmigos.destruirEntidades();
    }

    int Principal::executar() {
        relogio.restart();

        sf::Event e;

        while(!terminar) {
            sf::Time t = relogio.getElapsedTime();
            relogio.restart();

            if(gerenciadorGrafico.getJanela()->pollEvent(e)) {
                if(e.type == sf::Event::Closed) {
                    terminar = true;
                }
            }
            gerenciadorGrafico.limpar();
            listaAmigos.atualizarEntidades(t.asSeconds());
            listaAmigos.desenharEntidades(gerenciadorGrafico);
            gerenciadorGrafico.mostrar();
        }
        return 0;
    }
}
