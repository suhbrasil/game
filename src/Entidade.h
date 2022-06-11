#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ente.h"
using namespace sf;
using namespace std;


namespace entidades {
    class Entidade : public Ente {
    protected:
        float x;
        float y;

        Vector2f dimensoes;

        //animacao
        short estadoDeAnimacao;
        IntRect frameAtual;
        bool trocouAnimacao;
        Clock timerAnimacao;
    public:
        Sprite desenhavel;
        Texture textura;
        RectangleShape shape;

        Entidade();
        virtual ~Entidade();
        void inicializarDesenhavel();
        void inicializarAnimacao();
        virtual void inicializarVariaveis() = 0;

        void resetTimerAnimacao();

        const FloatRect getGlobalBounds() const;
        const Vector2f getPosition() const;
        const Vector2f getDimensoesMetade() const;

        void setPosition(const float x, const float y);

        void inicializarTextura();
        //renderTarget é responsável por definir o comportamento de objetos 2D
        void render(RenderTarget& target);
        void colidir(Entidade* p, Vector2f posicaoOutro, Vector2f dimensaoOutro);
        void executar() {}
    };
}
