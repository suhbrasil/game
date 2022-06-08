// #pragma once

// namespace lista
// {
//     template <typename TL>
//     class Lista
//     {
//     private:
//             template <typename TE>
//             class Elemento /*no da lista*/
//             {
//             private:
//                 TE info;
//                 Elemento *ant;
//                 Elemento *prox;

//             public:
//                 Elemento(TE Info = nullptr, Elemento* Ant = nullptr, Elemento* Prox = nullptr);
//                 ~Elemento();

//                 TE getInfo();
//                 void setInfo(TE Info);

//                 Elemento* getAnt();
//                 void setAnt(Elemento *Ant);

//                 Elemento* getProx();
//                 void setProx(Elemento *Prox);
//             };
//         Elemento<TL>* inicio;
//         Elemento<TL>* fim;
//         Elemento<TL>* atual;

//     public:
//         Lista();
//         ~Lista();

//         void inserir(TL info);
//         void retirar();

//         TL voltarInicio();
//         TL irProximo();
//     };
// }
