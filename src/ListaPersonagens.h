#ifndef _LISTAPERSONAGENS_H_
#define _LISTAPERSONAGENS_H_

#include "Personagem.h"

namespace sf {
    class RenderWindow;
}

namespace entidades {
    class ListaPersonagens
    {
    private:
        class ElementoLista {
        private:
            Personagem* info;
            ElementoLista* ant;
            ElementoLista* prox;
        public:
            ElementoLista(Personagem* Info = nullptr, ElementoLista* Ant = nullptr, ElementoLista* Prox = nullptr);
            ~ElementoLista();

            Personagem* getInfo();
            void setInfo(Personagem* Info);

            ElementoLista* getAnt();
            void setAnt(ElementoLista* Ant);

            ElementoLista* getProx();
            void setProx(ElementoLista* Prox);
        };
        ElementoLista* inicio;
        ElementoLista* fim;
        ElementoLista* atual;
    public:
        ListaPersonagens();
        ~ListaPersonagens();

        void inserir(Personagem* info);
        void esvaziar();
        Personagem* voltarInicio();
        Personagem* irProximo();

        void atualizarPersonagens(float t);
        void desenharPersonagens(sf::RenderWindow* janela);
        void destruirPersonagens();
    };
}

#endif
