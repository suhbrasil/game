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
    public:
        vector<Sprite> obstaculos;
        Obstaculo();
        ~Obstaculo();
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        int gerarAleatoriamente();
        void setPosicao();
        void desenharObstaculos(RenderWindow& janela);
    };
}
