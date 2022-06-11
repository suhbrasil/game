#include "FaseDois.h"
using namespace fases;


FaseDois::FaseDois(Jogador* j, GerenciadorGrafico* gf) : Fase(j, gf)
{
    id = 6;

    inicializarFundoTela();
    inicializarJogador(j);
    qtdeGalhos = gerarAleatoriamente(3,7);
    qtdeCogumelos = gerarAleatoriamente(3,7);
    gerarObstaculos();
}

FaseDois::~FaseDois()
{

}


void FaseDois::gerarCogumelos(){
   for (int i = 0 ; i < qtdeCogumelos; i++){
        Cogumelo* temp = new Cogumelo();
        cogumelos.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarObstaculo(temp);
    }
}

void FaseDois::gerarGalhos(){
   for (int i = 0 ; i < qtdeGalhos; i++){
        Galho* temp = new Galho();
        galhos.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarObstaculo(temp);
    }
}

void FaseDois::gerarObstaculos() {
    gerarGalhos();
    gerarCogumelos();
}

void FaseDois::atualizarRenderGalhos(int i) {
    Galho* galho = dynamic_cast <Galho*>(galhos.lista.getItem(i)->getInfo());
    galho->render(*janela);

}

void FaseDois::atualizarRenderCogumelos(int j) {
    Cogumelo* cogumelo = dynamic_cast <Cogumelo*>(cogumelos.lista.getItem(j)->getInfo());
    cogumelo->render(*janela);
}

void FaseDois::atualizarRenderObstaculos() {
    for (int i = 0 ; i < qtdeGalhos; i++){
       atualizarRenderGalhos(i);
    }

    for (int j = 0 ; j < qtdeCogumelos; j++){
       atualizarRenderCogumelos(j);
    }
}
