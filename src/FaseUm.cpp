#include "FaseUm.h"
using namespace fases;


FaseUm::FaseUm(Jogador* j, GerenciadorGrafico* gf) : Fase(j, gf)
{
    id = 7;

    inicializarFundoTela("texture/background.jpeg");
    inicializarJogador(j);
    qtdeGalhos = gerarAleatoriamente(7,3);
    qtdeEspinhos = gerarAleatoriamente(5,3);
    qtdeCartas = gerarAleatoriamente(10,3);
    qtdeGatos =  gerarAleatoriamente(7,3);
    gerarObstaculos();
    gerarInimigos();
}

FaseUm::~FaseUm()
{
}

void FaseUm::gerarGatos(){
   for (int i = 0 ; i < qtdeGatos; i++) {
        Gato* temp = new Gato();
        gatos.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarInimigo(temp);
    }
}

void FaseUm::gerarCartas(){
   for (int i = 0 ; i < qtdeCartas; i++) {
        Carta* temp = new Carta();
        cartas.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarInimigo(temp);
    }
}

void FaseUm::gerarInimigos() {
    gerarCartas();
    gerarGatos();
}


void FaseUm::gerarEspinhos(){
   for (int i = 0 ; i < qtdeEspinhos; i++) {
        Espinho* temp = new Espinho();
        espinhos.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarObstaculo(temp);
    }
}

void FaseUm::gerarGalhos(){
   for (int i = 0 ; i < qtdeGalhos; i++) {
        Galho* temp = new Galho();
        galhos.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarObstaculo(temp);
    }
}

void FaseUm::gerarObstaculos() {
    gerarGalhos();
    gerarEspinhos();
}

void FaseUm::atualizarRenderGatos(int i) {
    Gato* gato = dynamic_cast <Gato*>(gatos.lista.getItem(i)->getInfo());
    gato->render(*janela);
    gato->atualizar();

}

void FaseUm::atualizarRenderCartas(int j) {
    Carta* carta = dynamic_cast <Carta*>(cartas.lista.getItem(j)->getInfo());
    carta->render(*janela);
    carta->atualizar();
}

void FaseUm::atualizarRenderGalhos(int i) {
    Galho* galho = dynamic_cast <Galho*>(galhos.lista.getItem(i)->getInfo());
    galho->render(*janela);

}

void FaseUm::atualizarRenderEspinhos(int j) {
    Espinho* espinho = dynamic_cast <Espinho*>(espinhos.lista.getItem(j)->getInfo());
    espinho->render(*janela);
}

void FaseUm::atualizarRenderInimigos() {
    for (int i = 0 ; i < qtdeGatos; i++){
       atualizarRenderGatos(i);
    }

    for (int j = 0 ; j < qtdeCartas; j++){
       atualizarRenderCartas(j);
    }
}

void FaseUm::atualizarRenderObstaculos() {
    for (int i = 0 ; i < qtdeGalhos; i++){
       atualizarRenderGalhos(i);
    }

    for (int j = 0 ; j < qtdeEspinhos; j++){
       atualizarRenderEspinhos(j);
    }
}
