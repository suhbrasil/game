#include "Jogador.h"

#include <functional>
#include <iostream>

namespace entidades {
    // passa o IdsDesenhavel do jogador
    Jogador::Jogador(Vetor2F pos) :
    Colidivel(pos, Vetor2F(), IdsDesenhaveis::jogador,  "/Users/suzanabrasil/game/src/coelho.png")
    {

    }

    Jogador::~Jogador() {

    }

    void Jogador::inicializar(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
        gf.carregarTextura(caminho);
        dimensoes = gf.getTamanho(caminho);
        chaveOuvinte = ge.adicionarOuvinteTeclado( [this] (const sf::Event& e) {tratarEventos(e);} );
        gc.adicionarColidivel(this);
    }

    void Jogador::atualizar(float t) {
        posicao += v*t;
    }

    void Jogador::desenhar(GerenciadorGrafico& g) {
        g.desenhar(caminho, posicao);
        g.centralizar(posicao);
    }

    void Jogador::tratarEventos(const sf::Event& e) {
        if(e.type == sf::Event::KeyPressed) {
            switch (e.key.code)
            {
                case sf::Keyboard::Key::Right:
                    v.x += 100;
                    break;
                case sf::Keyboard::Key::Left:
                    v.x -= 100;
                    break;
                case sf::Keyboard::Key::Up:
                    v.y -= 100;
                    break;
                case sf::Keyboard::Key::Down:
                    v.y += 100;
                    break;
                default:
                    break;
            }
        } else if(e.type == sf::Event::KeyReleased) {
            switch (e.key.code)
            {
                case sf::Keyboard::Key::Right:
                    v.x -= 100;
                    break;
                case sf::Keyboard::Key::Left:
                    v.x += 100;
                    break;
                case sf::Keyboard::Key::Up:
                    v.y += 100;
                    break;
                case sf::Keyboard::Key::Down:
                    v.y -= 100;
                    break;
                default:
                    break;
            }
        }
    }

    void Jogador::colidir(IdsDesenhaveis::IdsDesenhaveis IDOutro, Vetor2F posicaoOutro, Vetor2F dimensoesOutro) {
        std::cout << "Colidiu" << std::endl;
    }
}
