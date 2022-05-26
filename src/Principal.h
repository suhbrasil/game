#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <SFML/System.hpp>

#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Vetor2D.h"
#include "Personagem.h"
#include "ListaEntidades.h"

namespace entidades {
    class Principal
    {
    private:
        bool terminar;
        GerenciadorGrafico gerenciadorGrafico;
        GerenciadorEventos gerenciadorEventos;
        sf::Clock relogio;
        ListaEntidades listaAmigos;
    public:
        Principal();
        ~Principal();
        int executar();
    };
}


#endif
