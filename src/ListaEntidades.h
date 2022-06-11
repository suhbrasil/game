#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Entidade.h"
#include "Lista.h"
using namespace lista;
using namespace entidades;

namespace lista {
    class ListaEntidades
    {
    private:

    public:
    Lista<Entidade*> lista;
        ListaEntidades();
        ~ListaEntidades();

        void inserir(Entidade* info);

        Entidade* voltarInicio(); // retorna para o início e retorna o primeiro elemento da lista
        Entidade* irProximo(); // vai para o próximo elemento da lista e retorna o próximo

        void atualizarEntidades(float t);
        void destruirEntidades();
    };
}

#endif
