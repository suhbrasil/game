#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "ListaPersonagens.h"

namespace entidades {
    class Principal
    {
    private:
        bool terminar;
        sf::RenderWindow* janela;
        sf::Clock relogio;
        ListaPersonagens listaAmigos;
    public:
        Principal();
        ~Principal();
        int executar();
    };
}


#endif
