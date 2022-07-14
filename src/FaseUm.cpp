#include "FaseUm.h"
using namespace fases;


FaseUm::FaseUm(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf) : Fase(j1, j2, gf)
{
    id = 7;

    inicializarFundoTela("texture/background.jpeg");
    inicializarPortal();
    inicializarJogador(j1, j2);
    qtdeGalhos = gerarAleatoriamente(7,3);
    qtdeEspinhos = gerarAleatoriamente(5,3);
    qtdeCartas = gerarAleatoriamente(6,3);
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

void FaseUm::gerarGatos() {
   for (int i = 0 ; i < qtdeGatos; i++) {
        Gato* temp = new Gato();
        gatos.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarInimigo(temp);
    }
}

void FaseUm::gerarCartas() {
   for (int i = 0 ; i < qtdeCartas; i++) {
        Carta* temp = new Carta();
        cartas.lista.inserir(dynamic_cast<Entidade*> (temp));
        temp->setPosicao(i);
        gerenciadorColisao.adicionarInimigo(temp);
    }
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

void FaseUm::gerarInimigos() {
    gerarCartas();
    gerarGatos();
}

void FaseUm::gerarObstaculos() {
    gerarGalhos();
    gerarEspinhos();
}

void FaseUm::gerarProjeteis() {
    if(tempoTiro < 1000)
        tempoTiro++;
    else{
        for(int i = 0; i < qtdeCartas; i++){
            Carta* carta = dynamic_cast <Carta*>(cartas.lista.getItem(i)->getInfo());
            Projetil* temp = new Projetil();
            temp->shape.setPosition(carta->getPosition().x , 650.f);
            carta->adicionarProjetil(temp);
            gerenciadorColisao.adicionarProjetil(temp);
        }
        tempoTiro = 0;
    }
}

void FaseUm::moverProjeteis() {
    for(int i = 0; i < qtdeCartas; i++){
        Carta* carta = dynamic_cast <Carta*>(cartas.lista.getItem(i)->getInfo());
        for(int j = 0; j < carta->getProjeteis().size(); j ++){

            janela->draw(carta->getProjeteis()[j]->shape);
            if(i%2 == 1)
                carta->getProjeteis()[j]->shape.move(0.5f,0.f);
            else
                carta->getProjeteis()[j]->shape.move(-0.5f,0.f);
            if(carta->getProjeteis()[j]->getPosition().x < 0.0f || carta->getProjeteis()[j]->getPosition().x > 2000.f)
                carta->getProjeteis().erase(carta->getProjeteis().begin()+i);
        }
    }
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
