#include "FaseUm.h"
using namespace fases;


FaseUm::FaseUm(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf) : Fase(j1, j2, gf)
{
    id = 7;

    inicializarFundoTela("texture/background.jpeg");
    inicializarPortal(fundoTelaTex.getSize().x - 620.f);
    inicializarJogador(j1, j2);
    qtdeGalhos = gerarAleatoriamente(7,3);
    qtdeEspinhos = gerarAleatoriamente(5,3);
    qtdeCartas = gerarAleatoriamente(10,3);
    qtdeGatos =  gerarAleatoriamente(7,3);
    gerarObstaculos();
    gerarInimigos();
}

FaseUm::~FaseUm()
{
    galhos.destruirEntidades();
    espinhos.destruirEntidades();
    gatos.destruirEntidades();
    cartas.destruirEntidades();
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

void FaseUm::gerarProjeteis() {

    if(tempoTiro < 1000) tempoTiro ++;

    else{
        Projetil* temp = new Projetil();
        temp->shape.setPosition(200.f , 650.f);
        projeteis.push_back(temp);
        gerenciadorColisao.adicionarProjetil(temp);
        tempoTiro = 0;
    }
}

void FaseUm::moverProjeteis() {
        for(int i = 0; i < projeteis.size(); i ++){
            janela->draw(projeteis[i]->shape);
            projeteis[i]->shape.move(0.5f,0.f);
            if(projeteis[i]->getPosition().x < 0.0f || projeteis[i]->getPosition().x > 2000.f) projeteis.erase(projeteis.begin()+i);
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
    gerarProjeteis();
    moverProjeteis();
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
