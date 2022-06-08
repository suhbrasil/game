#pragma once

#include <SFML/Graphics.hpp>

#include "GerenciadorGrafico.h"
using namespace gerenciadores;

class Ente
{
protected:
    GerenciadorGrafico* grafico;
    const char* caminho;
public:
    Ente(const char* caminhoText = nullptr);
    ~Ente();
    void desenharEnte();
    virtual void executar() = 0;
};
