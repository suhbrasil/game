#ifndef _LISTA_H_
#define _LISTA_H_

namespace lista
{
    template <typename TL>
    class Lista
    {
    private:
            template <typename TE>
            class Elemento /*no da lista*/
            {
            private:
                TE info;
                Elemento *ant;
                Elemento *prox;

            public:
                Elemento(TE Info = nullptr, Elemento *Ant = nullptr, Elemento *Prox = nullptr);
                ~Elemento();

                TE getInfo();
                void setInfo(TE Info);

                Elemento *getAnt();
                void setAnt(Elemento *Ant);

                Elemento *getProx();
                void setProx(Elemento *Prox);
            };


    public:
        Elemento<TL> *inicio;
        Elemento<TL> *fim;
        Elemento<TL> *atual;
        Lista();
        ~Lista();

        void inserir(TL info);
        void retirar();

        TL voltarInicio();
        TL irProximo();
        Elemento<TL>* getItem(int pos) {
            Elemento<TL>* temp = inicio;

            for(int i = 0; i < pos; i ++){
            temp = temp->getProx();
            }
            return temp;
        }
    };
}

#include "ListaImp.h"

#endif
