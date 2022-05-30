#include "Principal.h"
#include "Jogador.h"
#include "Inimigo.h"

#include <functional>

namespace entidades {
    Principal::Principal() :
        terminar(false),
        IDjanelaFechada(gerenciadorColisoes.adicionarOuvinteOutros( [this] (const sf::Event& e) {janelaFechar(e);} ))
    {
        listaAmigos.inserir(new Jogador(Vetor2F(0.0f, 0.0f)));
        listaAmigos.inserir(new Inimigo(Vetor2F(0.0f, 300.0f), Vetor2F(5, 5)));
        listaAmigos.inserir(new Inimigo(Vetor2F(200.0f, 200.0f), Vetor2F(10, 0)));
        listaAmigos.inserir(new Inimigo(Vetor2F(800.0f, 600.0f), Vetor2F(0, 5)));
        listaAmigos.inserir(new Inimigo(Vetor2F(400.0f, 0.0f), Vetor2F(5, 5)));

        listaAmigos.inicializarEntidades(gerenciadorGrafico, gerenciadorColisoes);
        gerenciadorColisoes.setJanela(gerenciadorGrafico.getJanela());
    }

    Principal::~Principal() {
        listaAmigos.destruirEntidades();
    }

    int Principal::executar() {
        relogio.restart();

        while(!terminar) {
            sf::Time t = relogio.getElapsedTime();
            relogio.restart();
            gerenciadorColisoes.tratarObstaculos();
            gerenciadorGrafico.limpar();
            listaAmigos.atualizarEntidades(t.asSeconds());
            listaAmigos.desenharEntidades(gerenciadorGrafico);
            gerenciadorGrafico.mostrar();
        }
        return 0;
    }

    void Principal::janelaFechar(const sf::Event& e) {
        if(e.type == sf::Event::Closed)
            terminar = true;
    }
}
