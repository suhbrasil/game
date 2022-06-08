#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace sf;
using namespace std;

namespace gerenciadores {
    class GerenciadorGrafico
    {
    private:
        RenderWindow* janela;
    public:
        GerenciadorGrafico();
        ~GerenciadorGrafico();
        void mostrar() const;
        void desenhar(const string caminhoText);
        RenderWindow* getJanela() const;
    };
}
