
#include "Lista.h"
using namespace lista;

template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>::Elemento(TE Info, Elemento<TE>* Ant, Elemento<TE>* Prox):
info(Info), ant(Ant), prox(Prox)
{

}

template <typename TL>
template <typename TE>
Lista<TL>::Elemento<TE>::~Elemento(){

}

template <typename TL>
template <typename TE>
TE Lista<TL>::Elemento<TE>::getInfo(){
    return info;

}

template <typename TL>
template <typename TE>
void Lista<TL>::Elemento<TE>::setInfo(TE Info){
    info = Info;
}

template <typename TL>
template <typename TE>
typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getAnt(){
    return ant;
}

template <typename TL>
template <typename TE>
void Lista<TL>::Elemento<TE>::setAnt(Elemento<TE>* Ant){
    ant = Ant;
}

template <typename TL>
template <typename TE>
typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getProx(){
    return prox;
}

template <typename TL>
    template <typename TE>
    void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* Prox){
        prox = Prox;
    }

template <typename TL>
Lista<TL>::Lista() :
inicio(nullptr), fim(nullptr), atual(nullptr)
{

}

template <typename TL>
Lista<TL>::~Lista(){
    retirar();
}

template <typename TL>
    void Lista<TL>::inserir(TL info){
        if(info) {
            Elemento<TL>* novo = new Elemento<TL>(info);

            if(!inicio) {
                inicio = novo;
                fim = novo;
            } else {
                fim->setProx(novo);
                novo->setAnt(fim);

                fim = novo;
            }
        }
    }

template <typename TL>
void Lista<TL>::retirar(){
    Elemento<TL>* Paux = inicio;
    atual = inicio;

    while(atual != nullptr) {
        Paux = atual->getProx();
        delete atual;
        atual = Paux;
    }

    inicio = nullptr;
    fim = nullptr;
    atual = nullptr;
}

template <typename TL>
TL Lista<TL>::voltarInicio(){
    atual = inicio;
    if(atual) {
        return atual->getInfo();
    } else {
        return nullptr;
    }
}

template <typename TL>
TL Lista<TL>::irProximo(){
    atual = atual->getProx();
    if(atual)
        return atual->getInfo();
    else
        return nullptr;
}
