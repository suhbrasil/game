#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"
#include <iostream>
#include <cstdlib>
using namespace sf;
using namespace entidades;

namespace obstaculos {
    class Obstaculo : public Entidade {
    protected:
        bool dano;
        int quantidadeInstancias;
        float posicaoX;
    public:
        vector<Sprite> obstaculos;
        Obstaculo();
        ~Obstaculo();
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        int gerarAleatoriamente(int maior, int menor);
        void setPosicao(int i);
        void desenharObstaculos(RenderWindow& janela);
        float operator+(float i);
    };
}
