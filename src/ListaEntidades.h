#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Ente.h"
#include "Lista.h"

namespace entidades {
    class GerenciadorGrafico;
    class GerenciadorEventos;
    class GerenciadorColisoes;

    class ListaEntidades
    {
    private:
        Lista<Ente*> lista;
    public:
        ListaEntidades();
        ~ListaEntidades();

        void inserir(Ente* info);

        Ente* voltarInicio(); // retorna para o início e retorna o primeiro elemento da lista
        Ente* irProximo(); // vai para o próximo elemento da lista e retorna o próximo

        void inicializarEntidades(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc);
        void atualizarEntidades(float t);
        void desenharEntidades(GerenciadorGrafico& g);
        void destruirEntidades();
    };
}

#endif
