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
        float posicaoX;
        float posicaoY;
        bool ePlataforma;
        bool eEspinho;
    public:
        vector<Sprite> obstaculos;
        Obstaculo();
        ~Obstaculo();
        void inicializarVariaveis();
        void inicializarTextura() ;
        void inicializarDesenhavel();
        const bool getEPlataforma() const;
        const bool getEEspinho() const;
        void setPosicao(int i);
        void desenharObstaculos(RenderWindow& janela);
    };
}
