#include "GerenciadorColisoes.h"

namespace entidades {
    unsigned int GerenciadorColisoes::proximoID(0);

    GerenciadorColisoes::GerenciadorColisoes() {

    }

    GerenciadorColisoes::~GerenciadorColisoes() {

    }

    void GerenciadorColisoes::tratarObstaculos() {
        while(janela->pollEvent(evento))
        {
            if(evento.type == sf::Event::MouseWheelScrolled
                || evento.type == sf::Event::MouseButtonPressed
                || evento.type == sf::Event::MouseButtonReleased
                || evento.type == sf::Event::MouseMoved ) {

                    for(auto it : ouvintesMouse) {
                        it.second(evento);
                    }

            } else if(evento.type == sf::Event::KeyPressed
                || evento.type == sf::Event::KeyReleased ) {

                    for(auto it : ouvintesTeclado) {
                        it.second(evento);
                    }

            } else {
                for(auto it : ouvintesOutros) {
                    it.second(evento);
                }
            }
        }
    }

    void GerenciadorColisoes::setJanela(sf::RenderWindow* j) {
        janela = j;

        // faz com que quando a gente pressionar alguma tecla a velocidade fique constante e não que vá aumentando
        janela->setKeyRepeatEnabled(false);
    }

    unsigned int GerenciadorColisoes::adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada) {
        // ouvintesMouse.emplace(proximoID, chamada);
        ouvintesMouse.insert(std::pair<unsigned int, std::function<void(const sf::Event&)> >(proximoID, chamada));
        return proximoID++;
    }
    void GerenciadorColisoes::removerOuvinteMouse(int id) {
        ouvintesMouse.erase(id);
    }

    unsigned int GerenciadorColisoes::adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada) {
        // ouvintesTeclado.emplace(proximoID, chamada);
        ouvintesTeclado.insert(std::pair<unsigned int, std::function<void(const sf::Event&)> >(proximoID, chamada));
        return proximoID++;
    }
    void GerenciadorColisoes::removerOuvinteTeclado(int id) {
        ouvintesTeclado.erase(id);
    }

    unsigned int GerenciadorColisoes::adicionarOuvinteOutros(std::function<void(const sf::Event&)> chamada) {
        // ouvintesOutros.emplace(proximoID, chamada);
        ouvintesOutros.insert(std::pair<unsigned int, std::function<void(const sf::Event&)> >(proximoID, chamada));
        return proximoID++;
    }
    void GerenciadorColisoes::removerOuvinteOutros(int id) {
        ouvintesOutros.erase(id);
    }
}
