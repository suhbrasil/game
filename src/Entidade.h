#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;


namespace entidades {

    class Entidade {

    protected:
        Sprite desenhavel;
        Texture textura;

        //animacao
        short estadoDeAnimacao;
        IntRect frameAtual;
        bool trocouAnimacao;
        Clock timerAnimacao;
    public:

        Entidade();
        ~Entidade();
        //virtual void executar();
        void inicializarDesenhavel();
        void inicializarAnimacao();

        void resetTimerAnimacao();

        const FloatRect getGlobalBounds() const;
        const Vector2f  getPosition() const;

        void setPosition(const float x, const float y);

        void inicializarTextura();
        //renderTarget é responsável por definir o comportamento de objetos 2D
        void render(RenderTarget& target);
    };
}
