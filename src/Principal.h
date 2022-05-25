#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <SFML/System.hpp>

#include "GerenciadorGrafico.h"
#include "Vetor2D.h"
#include "Personagem.h"
#include "ListaPersonagens.h"

namespace entidades {
    class Principal
    {
    private:
        bool terminar;
        GerenciadorGrafico gerenciadorGrafico;
        sf::Clock relogio;
        ListaPersonagens listaAmigos;
    public:
        Principal();
        ~Principal();
        int executar();
    };
}


#endif
