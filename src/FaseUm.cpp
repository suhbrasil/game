#include "FaseUm.h"
using namespace fases;


FaseUm::FaseUm(Jogador* j, GerenciadorGrafico* gf) : Fase(j, gf)
{
    inicializarFundoTela();
    inicializarBotaoPausar();
    inicializarJogador(j);
    qtdeGalhos = 1;
    qtdeEspinhos = 1;
    gerarObstaculos();
}

FaseUm::~FaseUm()
{
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

void FaseUm::atualizarRenderGalhos(int i) {
    Galho* galho = dynamic_cast <Galho*>(galhos.lista.getItem(i)->getInfo());
    galho->render(*janela);

}

void FaseUm::atualizarRenderEspinhos(int j) {
    Espinho* espinho = dynamic_cast <Espinho*>(espinhos.lista.getItem(j)->getInfo());
    espinho->render(*janela);
}

void FaseUm::atualizarRenderObstaculos() {
    for (int i = 0 ; i < qtdeGalhos; i++){
       atualizarRenderGalhos(i);
    }

    for (int j = 0 ; j < qtdeEspinhos; j++){
       atualizarRenderEspinhos(j);
    }
}
