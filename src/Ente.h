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
    void imprimir();
    virtual void executar() = 0;
};
