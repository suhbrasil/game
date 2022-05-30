#ifndef _LISTA_H_
#define _LISTA_H_


namespace entidades {
    template <typename TL>
    class Lista
    {
    private:
        template <typename TE>
        class Elemento {
        private:
            TE info;
            Elemento* ant;
            Elemento* prox;
        public:
            Elemento(TE Info = nullptr, Elemento* Ant = nullptr, Elemento* Prox = nullptr);
            ~Elemento();

            TE getInfo();
            void setInfo(TE Info);

            Elemento* getAnt();
            void setAnt(Elemento* Ant);

            Elemento* getProx();
            void setProx(Elemento* Prox);
        };
        Elemento<TL>* inicio;
        Elemento<TL>* fim;
        Elemento<TL>* atual;
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
