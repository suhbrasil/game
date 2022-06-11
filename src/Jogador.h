#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <fstream> // ofstream e ifstream
#include <string.h>
#include "Personagem.h"

#define ESTADOINICIAL 0
#define PULO 1
#define SEGUNDOESTADO 2

using namespace sf;

namespace personagens {
    class Jogador : public Personagem {
    private:
        // contar quantas vezes o teclado já foi pressionado (deixará a mudança de frame mais lenta)
        int countFrame;
        int pontos;
        //fisica
        bool movimentando;
        float velocidadeMaxima;
        float velocidadeMinima;
        Vector2f velocidade;
        float aceleracao;
        float atrito;
        float gravidade;
        float velocidadeMaximaY;
        float velocidadeMinimaY;
        float posicaoInicialY;
        float posicaoInicialX;

        bool podePular;
        float alturaPulo;
    public:
        Jogador();
        virtual ~Jogador();

        void atualizar();
        void inicializarVariaveis();
        void inicializarFenomenosFisicos();

        void resetVelocidadeY();
        void resetVelocidadeX();
        void atualizarAnimacao();
         //movimentar do teclado
        void atualizarMovimentacao();
        void atualizarFenomenosFisicos();
        //movimentar fisicamente (diz a direcao do movimento)
        void movimentar(const float direcaoX, const float direcaoY);
        Vector2f getVelocidade();
        bool getPodePular();
        void setPodePular(bool pular);
        void diminuirPontos();
        int getPontos();
        void executar() {}
    };
}
