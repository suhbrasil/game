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

        bool movimentando;

        bool podePular;
    public:
        Jogador();
        virtual ~Jogador();

        void setTextura(const char* caminho);
        void inicializarDesenhavel();
        void atualizar1();
        void atualizar2();
        void inicializarVariaveis();
        void atualizarAnimacao();
        void atualizarMovimentacaoJ1();
        void atualizarMovimentacaoJ2();
        void movimentar(const float direcaoX, const float direcaoY);
        Vector2f getVelocidade();
        bool getPodePular();
        void setPodePular(bool pular);
        void diminuirPontos(int ponto);
        void ganharPontos(int ponto);
        int getPontos();
        void resetPosicao();
        void executar() {}
    };
}
