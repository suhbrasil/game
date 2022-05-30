#include "Jogador.h"

#include <functional>

namespace entidades {
    Jogador::Jogador(Vetor2F pos) :
    Personagem(pos, Vetor2F(), "/Users/suzanabrasil/game/src/coelho.png")
    {

    }

    Jogador::~Jogador() {

    }

    void Jogador::inicializar(GerenciadorGrafico &gf, GerenciadorColisoes &gc) {
        gf.carregarTextura(caminho);
        chaveOuvinte = gc.adicionarOuvinteTeclado( [this] (const sf::Event& e) {tratarObstaculo(e);} );
    }

    void Jogador::atualizar(float t) {
        posicao += v*t;
    }

    void Jogador::desenhar(GerenciadorGrafico &g) {
        g.desenhar(caminho, posicao);
    }

    void Jogador::tratarObstaculo(const sf::Event& e) {
        if(e.type == sf::Event::KeyPressed) {
            switch (e.key.code)
            {
                case sf::Keyboard::Key::Right:
                    v.x += 10;
                    break;
                case sf::Keyboard::Key::Left:
                    v.x -= 10;
                    break;
                case sf::Keyboard::Key::Up:
                    v.y -= 10;
                    break;
                case sf::Keyboard::Key::Down:
                    v.y += 10;
                    break;
                default:
                    break;
            }
        } else if(e.type == sf::Event::KeyReleased) {
            switch (e.key.code)
            {
                case sf::Keyboard::Key::Right:
                    v.x -= 10;
                    break;
                case sf::Keyboard::Key::Left:
                    v.x += 10;
                    break;
                case sf::Keyboard::Key::Up:
                    v.y += 10;
                    break;
                case sf::Keyboard::Key::Down:
                    v.y -= 10;
                    break;
                default:
                    break;
            }
        }
    }
}
