#ifndef _LISTA_H_
#define _LISTA_H_


namespace entidades {
    template <typename TL>
    class Lista
    {
    private:
        template <typename TE>
        class ElementoLista {
        private:
            TE info;
            ElementoLista* ant;
            ElementoLista* prox;
        public:
            ElementoLista(TE Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
            ~ElementoLista();

            TE getInfo();
            void setInfo(TE Info);

            ElementoLista* getAnt();
            void setAnt(ElementoLista* Ant);

            ElementoLista* getProx();
            void setProx(ElementoLista* Prox);
        };
        ElementoLista<TL>* inicio;
        ElementoLista<TL>* fim;
        ElementoLista<TL>* atual;
    public:
        Lista();
        ~Lista();

        void inserir(TL info);
        void esvaziar();

        TL voltarInicio();
        TL irProximo();
    };
}

#include "ListaImplementacao.h"

#endif
