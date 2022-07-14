#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ente.h"
using namespace sf;
using namespace std;


namespace entidades {
    class Entidade : public Ente {
    protected:
        float posicaoX;
        float posicaoY;

        Vector2f dimensoes;

        //animacao
        short estadoDeAnimacao;
        IntRect frameAtual;
        bool trocouAnimacao;
        Clock timerAnimacao;
    public:
        Sprite desenhavel;
        Texture textura;

        Entidade();
        virtual ~Entidade();
        void inicializarTextura(const char* caminho);
        void inicializarDesenhavel();
        void inicializarAnimacao();
        virtual void inicializarVariaveis() = 0;

        void resetTimerAnimacao();

        const FloatRect getGlobalBounds() const;
        const Vector2f getPosition() const;
        void setPosition(const float x, const float y);
        const Vector2f getDimensoesMetade() const;

        //renderTarget é responsável por definir o comportamento de objetos 2D
        void render(RenderTarget& target);
        void colidir(Entidade* p, Vector2f posicaoOutro, Vector2f dimensaoOutro);
        void executar() {}
    };
}
