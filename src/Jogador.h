#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;

namespace entidades {
    class Jogador {
    private:
        Sprite desenhavel;
        Texture textura;
        short estadoDeAnimacao;
        IntRect frameAtual;
        // contar quantas vezes o teclado já foi pressionado (deixará a mudança de frame mais lenta)
        int countFrame;
        Clock timerAnimacao;
        bool movimentando;
    public:
        Jogador();
        virtual ~Jogador();

        void atualizar();
        //renderTarget é responsável por definir o comportamento de objetos 2D
        void render(RenderTarget& target);
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        void inicializarAnimacao();
        void atualizarAnimacao();
        void movimentar();
    };
}
