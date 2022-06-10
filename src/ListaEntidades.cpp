#include "ListaEntidades.h"
using namespace lista;


ListaEntidades::ListaEntidades()
{

}

ListaEntidades::~ListaEntidades() {
        destruirEntidades();
}

void ListaEntidades::inserir(Entidade* info){
        lista.inserir(info);
}



void ListaEntidades::destruirEntidades(){
    Entidade* p = lista.voltarInicio();
    while (p)
    {
        delete p;
        p = lista.irProximo();
    }

    lista.retirar();
}
