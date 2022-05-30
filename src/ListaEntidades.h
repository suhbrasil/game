#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Personagem.h"
#include "Lista.h"

namespace entidades {
    class ListaEntidades
    {
    private:
        Lista<Personagem*> lista;
    public:
        ListaEntidades();
        ~ListaEntidades();

        void inserir(Personagem* info);

        Personagem* voltarInicio(); // retorna para o início e retorna o primeiro elemento da lista
        Personagem* irProximo(); // vai para o próximo elemento da lista e retorna o próximo

        void inicializarEntidades(GerenciadorGrafico &gf, GerenciadorColisoes &gc);
        void atualizarEntidades(float t);
        void desenharEntidades(GerenciadorGrafico &g);
        void destruirEntidades();
    };
}

#endif
