#pragma once

#include <SFML/Graphics.hpp>

class Ente
{
private:
public:
    Ente() {}
    ~Ente() {}
    virtual void executar() = 0;
};
