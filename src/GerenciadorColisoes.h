#pragma once

#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "ListaEntidades.h"

#include <iostream>
#include <vector>
#include <list>
#include <math.h>

using namespace personagens;
using namespace obstaculos;
using namespace std;
// using namespace lista;

namespace gerenciadores {
    class GerenciadorColisoes {
    private:
        int contar;
        vector<Inimigo*> inimigos;
        list<Obstaculo*> obstaculos;

        FloatRect proxPosicao;
    public:
        GerenciadorColisoes();
        ~GerenciadorColisoes();
        void adicionarObstaculo(Obstaculo* obstaculo);
        void adicionarInimigo(Inimigo* inimigo);
        Obstaculo* getObstaculo();
        Inimigo* getInimigo();

        void verificarColisoes(RenderWindow &janela, Jogador *jogador);
        void verificarColisaoJogadorInimigo(Jogador* jogador);
        void verificarColisaoJogadorObstaculo(Jogador* jogador);
        void verificarColisaoObstaculoInimigo();
        void verificarColisaoChao(RenderWindow &janela, Jogador *jogador);
        void verificarColisaoInimigoInimigo();

        bool colisaoDireita(FloatRect entidade1, FloatRect entidade2);
        bool colisaoEsquerda(FloatRect entidade1, FloatRect entidade2);
        bool colisaoInferior(FloatRect entidade1, FloatRect entidade2);
        bool colisaoSuperior(FloatRect entidade1, FloatRect entidade2);

        void verificarColisaoInicioTelaJogador(Jogador* jogador);
        void verificarColisaoInicioTelaRainha(Inimigo* inimigo);
    };

}
