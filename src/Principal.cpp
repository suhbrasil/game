#include "Principal.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Carta.h"
#include "Gato.h"

namespace entidades {
    Principal::Principal() :
        terminar(false),
        IDjanelaFechada(gerenciadorEventos.adicionarOuvinteOutros( [this] (const sf::Event& e) {janelaFechar(e);} ))
    {
        listaAmigos.inserir(new Jogador(Vetor2F(0.0f, 0.0f)));
        listaAmigos.inserir(new Carta(Vetor2F(-200.0f, -500.0f), Vetor2F(100, 100)));
        listaAmigos.inserir(new Inimigo(Vetor2F(-200.0f, 500.0f), Vetor2F(-100, -100)));
        listaAmigos.inserir(new Gato(Vetor2F(200.0f, -500.0f), Vetor2F(100, 100)));

        listaAmigos.inicializarEntidades(gerenciadorGrafico, gerenciadorEventos, gerenciadorColisoes);
        gerenciadorEventos.setJanela(gerenciadorGrafico.getJanela());
    }

    Principal::~Principal() {
        listaAmigos.destruirEntidades();
    }

    int Principal::executar() {
        relogio.restart();

        while(!terminar) {
            sf::Time t = relogio.getElapsedTime();
            relogio.restart();
            gerenciadorEventos.tratarEventos();
            gerenciadorGrafico.limpar();
            listaAmigos.atualizarEntidades(t.asSeconds());
            gerenciadorColisoes.verificarColisoes();
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
