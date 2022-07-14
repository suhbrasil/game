#pragma once

#include <SFML/Graphics.hpp>

class Ente
{
protected:
    int id;
public:
    Ente();
    ~Ente();
    int getId();
    virtual void executar() = 0;
};
