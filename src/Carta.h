#pragma once

#include <SFML/Graphics.hpp>
#include "Inimigo.h"
#include <vector>
#include "Projetil.h"
using namespace sf;
using namespace std;

namespace personagens {
    class Carta : public Inimigo {
    private:
        int tempoTiro;
        vector<Projetil*> projeteis;
    public:
        Carta();
        ~Carta();
        void inicializarVariaveis();
        void inicializarTextura();
        void inicializarDesenhavel();
        void adicionarProjetil(Projetil *projetil);
        const int getTempoTiro() const;
        void setTempoTiro(int tempo);
        vector<Projetil*> getProjeteis();
        float operator+(float i);
        void setPosicao(int i);
    };
}
