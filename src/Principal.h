#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <SFML/System.hpp>

#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Vetor2D.h"
#include "Personagem.h"
#include "ListaEntidades.h"

namespace entidades {
    class Principal
    {
    private:
        bool terminar;
        GerenciadorGrafico gerenciadorGrafico;
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
