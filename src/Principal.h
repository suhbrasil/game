#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <SFML/System.hpp>

#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"
#include "Vetor2D.h"
#include "Ente.h"
#include "ListaEntidades.h"

namespace entidades {
    class Principal
    {
    private:
        bool terminar;
        GerenciadorGrafico gerenciadorGrafico;
        GerenciadorEventos gerenciadorEventos;
        GerenciadorColisoes gerenciadorColisoes;
        sf::Clock relogio;
        ListaEntidades listaAmigos;
        unsigned int IDjanelaFechada;
    public:
        Principal();
        ~Principal();
        int executar();
        void janelaFechar(const sf::Event& e);
    };
}


#endif
