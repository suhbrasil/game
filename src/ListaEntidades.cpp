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
        Personagem* p = voltarInicio();
        while (p)
        {
            p->desenhar(g);
            p = irProximo();
        }
    }

    void ListaEntidades::destruirEntidades(){
        Personagem* p = voltarInicio();
        while (p)
        {
            delete p;
            p = irProximo();
        }

        lista.esvaziar();
    }
}
