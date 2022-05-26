namespace entidades
{
    template <typename TL>
    template <typename TE>
    Lista<TL>::ElementoLista<TE>::ElementoLista(TE Info, ElementoLista<TE>* Ant, ElementoLista<TE>* Prox) :
    info(Info), ant(Ant), prox(Prox)
    {

    }

    template <typename TL>
    template <typename TE>
    Lista<TL>::ElementoLista<TE>::~ElementoLista(){

    }

    template <typename TL>
    template <typename TE>
    TE Lista<TL>::ElementoLista<TE>::getInfo(){
        return info;
    }

    template <typename TL>
    template <typename TE>
    void Lista<TL>::ElementoLista<TE>::setInfo(TE Info){
        info = Info;
    }

    template <typename TL>
    template <typename TE>
    Lista<TL>::ElementoLista<TE>* Lista<TL>::ElementoLista<TE>::getAnt(){
        return ant;
    }

    template <typename TL>
    template <typename TE>
    void Lista<TL>::ElementoLista<TE>::setAnt(ElementoLista<TE>* Ant){
        ant = Ant;
    }

    template <typename TL>
    template <typename TE>
    Lista<TL>::ElementoLista<TE>* Lista<TL>::ElementoLista<TE>::getProx(){
        return prox;
    }

    template <typename TL>
    template <typename TE>
    void Lista<TL>::ElementoLista<TE>::setProx(ElementoLista<TE>* Prox){
        prox = Prox;
    }

    template <typename TL>
    Lista<TL>::Lista() :
    inicio(nullptr), fim(nullptr), atual(nullptr)
    {

    }

    template <typename TL>
    Lista<TL>::~Lista(){
        esvaziar();
    }

    template <typename TL>
    void Lista<TL>::inserir(TL info){
        if(info) {
            ElementoLista<TL>* novo = new ElementoLista<TL>(info);

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
    void Lista<TL>::esvaziar(){
        ElementoLista<TL>* Paux = inicio;
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

    template <typename T>
    T Lista<T>::irProximo(){
        atual = atual->getProx();
        if(atual)
            return atual->getInfo();
        else
            return nullptr;
    }
}
