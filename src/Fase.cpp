#include "Fase.h"
using namespace fases;


Fase::Fase(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf) : Ente(), gerenciadorGrafico(gf)
{
    id = 5;
    inicializarJogador(j1, j2);
    janela = gerenciadorGrafico->getJanela();
}

Fase::~Fase()
{

}


void Fase::inicializarFundoTela(const char* caminho) {
    if(!fundoTelaTex.loadFromFile(caminho))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void Fase::renderFundoTela() {
    janela->draw(fundoTela);
}

Texture Fase::getFundoTela() {
    return fundoTelaTex;
}

void Fase::salvarJogada() {
    ofstream arq("jogada.txt", fstream::app);
    arq << jogador1->getPosition().x << "\n" << jogador1->getPosition().y << "\n";
    arq.close();
}

void Fase::pausarJogada() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        salvarJogada();
        janela->close();
    }
}

void Fase::verPontos() {
    if(jogador1->getPontos() <= 0 && jogador2->getPontos() > 0) {
        jogador1->setPosition(-100.f, 900.f);
    }
    else if (jogador1->getPontos() > 0 && jogador2->getPontos() <= 0)
        jogador2->setPosition(-100.f, 900.f);
    else
        janela->close();
}

void Fase::inicializarJogador(Jogador* j1, Jogador* j2)
{
    jogador1 = new Jogador();
    jogador2 = new Jogador();
    jogador1 = j1;
    jogador2 = j2;
}

void Fase::atualizarJogador1()
{
    jogador1->atualizarMovimentacaoJ1();
    jogador1->atualizar();
}

void Fase::atualizarJogador2() {
    jogador2->atualizarMovimentacaoJ2();
    jogador2->atualizar();
}

void Fase::atualizar()
{
    while (janela->pollEvent(event))
    {
        if (event.type == Event::Closed)
            janela->close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            janela->close();

        if(event.type ==  Event::KeyReleased &&
            (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Up ||
                 event.key.code == Keyboard::Down || event.key.code == Keyboard::Left
                    || event.key.code == Keyboard::Right))
        {
            jogador1->resetTimerAnimacao();
            jogador2->resetTimerAnimacao();
        }
    }

    atualizarJogador1();
    atualizarJogador2();
    atualizarColisao();
}

void Fase::atualizarRenderJogador() {
    jogador1->render(*janela);
    jogador2->render(*janela);
}

void Fase::atualizarColisao() {
    gerenciadorColisao.verificarColisoes(*janela, jogador1);
    gerenciadorColisao.verificarColisoes(*janela, jogador2);
}

void Fase::render()
{
    renderFundoTela();
    atualizarRenderJogador();
    atualizarRenderObstaculos();
    atualizarRenderInimigos();

    janela->display();
}


void Fase::executar() {
    janela->clear();
    gerenciadorGrafico->centralizar(jogador1->getPosition());
    pausarJogada();
    verPontos();
    atualizar();
    render();
}

int Fase::gerarAleatoriamente(int maior, int menor) {
    srand(time(NULL));
    int aleatorio = rand()%(maior-menor)+1 + menor;

    return aleatorio;
}
