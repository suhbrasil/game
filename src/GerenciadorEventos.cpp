#include "GerenciadorEventos.h"

namespace entidades {
    unsigned int GerenciadorEventos::proximoID(0);

    GerenciadorEventos::GerenciadorEventos() {

    }

    GerenciadorEventos::~GerenciadorEventos() {

    }

    void GerenciadorEventos::tratarEventos() {
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

    void GerenciadorEventos::setJanela(sf::RenderWindow* j) {
        janela = j;

        // faz com que quando a gente pressionar alguma tecla a velocidade fique constante e não que vá aumentando
        janela->setKeyRepeatEnabled(false);
    }

    unsigned int GerenciadorEventos::adicionarOuvinteMouse(std::function<void(const sf::Event&)> chamada) {
        // ouvintesMouse.emplace(proximoID, chamada);
        ouvintesMouse.insert(std::pair<unsigned int, std::function<void(const sf::Event&)> >(proximoID, chamada));
        return proximoID++;
    }
    void GerenciadorEventos::removerOuvinteMouse(int id) {
        ouvintesMouse.erase(id);
    }

    unsigned int GerenciadorEventos::adicionarOuvinteTeclado(std::function<void(const sf::Event&)> chamada) {
        // ouvintesTeclado.emplace(proximoID, chamada);
        ouvintesTeclado.insert(std::pair<unsigned int, std::function<void(const sf::Event&)> >(proximoID, chamada));
        return proximoID++;
    }
    void GerenciadorEventos::removerOuvinteTeclado(int id) {
        ouvintesTeclado.erase(id);
    }

    unsigned int GerenciadorEventos::adicionarOuvinteOutros(std::function<void(const sf::Event&)> chamada) {
        // ouvintesOutros.emplace(proximoID, chamada);
        ouvintesOutros.insert(std::pair<unsigned int, std::function<void(const sf::Event&)> >(proximoID, chamada));
        return proximoID++;
    }
    void GerenciadorEventos::removerOuvinteOutros(int id) {
        ouvintesOutros.erase(id);
    }
}
