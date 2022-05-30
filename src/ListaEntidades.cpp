#include "ListaEntidades.h"

namespace entidades
{
    ListaEntidades::ListaEntidades()
    {

    }

    ListaEntidades::~ListaEntidades() {
        destruirEntidades();
    }

    void ListaEntidades::inserir(Personagem* info){
        lista.inserir(info);
    }

    void ListaEntidades::inicializarEntidades(GerenciadorGrafico &gf, GerenciadorEventos &ge) {
        Personagem* p = lista.voltarInicio();
        while (p)
        {
            p->inicializar(gf, ge);
            p = lista.irProximo();
        }
    }

    void ListaEntidades::atualizarEntidades(float t){
        Personagem* p = lista.voltarInicio();
        while (p)
        {
            p->atualizar(t);
            p = lista.irProximo();
        }
    }

    void ListaEntidades::desenharEntidades(GerenciadorGrafico &g){
        Personagem* p = lista.voltarInicio();
        while (p)
        {
            p->desenhar(g);
            p = lista.irProximo();
        }
    }

    void ListaEntidades::destruirEntidades(){
        Personagem* p = lista.voltarInicio();
        while (p)
        {
            delete p;
            p = lista.irProximo();
        }

        lista.esvaziar();
    }
}
