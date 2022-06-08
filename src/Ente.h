#pragma once

#include <SFML/Graphics.hpp>

#include "GerenciadorColisoes.h"
using namespace gerenciadores;

class Ente
{
private:
public:
    Ente() {}
    ~Ente() {}
    virtual void executar() = 0;
};
