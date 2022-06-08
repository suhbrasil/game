#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


namespace entidades {
    class Entidade {
    protected:
        float x;
        float y;


        //animacao
        short estadoDeAnimacao;
        IntRect frameAtual;
        bool trocouAnimacao;
        Clock timerAnimacao;
    public:
        Sprite desenhavel;
        Texture textura;
        Entidade();
        ~Entidade();
        //virtual void executar();
        void inicializarDesenhavel();
        void inicializarAnimacao();
        virtual void inicializarVariaveis() = 0;

        void resetTimerAnimacao();

        const FloatRect getGlobalBounds() const;
        const Vector2f getPosition() const;

        void setPosition(const float x, const float y);

        void inicializarTextura();
        //renderTarget é responsável por definir o comportamento de objetos 2D
        void render(RenderTarget& target);
    };
}
