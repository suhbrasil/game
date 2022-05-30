#include "ListaEntidades.h"

namespace entidades
{
    ListaEntidades::ListaEntidades()
    {

    }

    ListaEntidades::~ListaEntidades() {
        destruirEntidades();
    }

    void ListaEntidades::inserir(Ente* info){
        lista.inserir(info);
    }

    void ListaEntidades::inicializarEntidades(GerenciadorGrafico& gf, GerenciadorEventos& ge, GerenciadorColisoes& gc) {
        Ente* p = lista.voltarInicio();
        while (p)
        {
            p->inicializar(gf, ge, gc);
            p = lista.irProximo();
        }
    }

    void ListaEntidades::atualizarEntidades(float t){
        Ente* p = lista.voltarInicio();
        while (p)
        {
            p->atualizar(t);
            p = lista.irProximo();
        }
    }

    void ListaEntidades::desenharEntidades(GerenciadorGrafico& g){
        Ente* p = lista.voltarInicio();
        while (p)
        {
            p->desenhar(g);
            p = lista.irProximo();
        }
    }

    void ListaEntidades::destruirEntidades(){
        Ente* p = lista.voltarInicio();
        while (p)
        {
            delete p;
            p = lista.irProximo();
        }

        lista.esvaziar();
    }
}
