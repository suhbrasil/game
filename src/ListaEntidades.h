#pragma once

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

        Entidade* voltarInicio();
        Entidade* irProximo();

        void atualizarEntidades(float t);
        void destruirEntidades();
    };
}
