#include "Fase.h"
using namespace fases;


Fase::Fase(Jogador* j, GerenciadorGrafico* gf) : Ente(), gerenciadorGrafico(gf)
{
    id = 5;
    inicializarFundoTela();
    inicializarJogador(j);
    janela = gerenciadorGrafico->getJanela();
}

Fase::~Fase()
{

}


void Fase::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("texture/background.jpeg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void Fase::renderFundoTela() {
    janela->draw(fundoTela);
}

void Fase::salvarJogada() {
    ofstream arq("jogada.txt", fstream::app);
    arq << jogador->getPosition().x << "\n" << jogador->getPosition().y << "\n";
    arq.close();
}

void Fase::pausarJogada() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        salvarJogada();
        janela->close();
    }
}

void Fase::verPontos() {
    if(jogador->getPontos() <= 0)
        janela->close();
}

void Fase::inicializarJogador(Jogador* j)
{
    jogador = new Jogador();
    jogador = j;
}

void Fase::atualizarJogador()
{
    jogador->atualizar();
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

            jogador->resetTimerAnimacao();
    }

    atualizarJogador();
    atualizarColisao();
}

void Fase::atualizarRenderJogador() {
    jogador->render(*janela);
}

void Fase::atualizarColisao() {
    gerenciadorColisao.verificarColisoes(*janela, jogador);
}

void Fase::render()
{
    renderFundoTela();
    atualizarRenderJogador();
    atualizarRenderObstaculos();

    janela->display();
}

void Fase::executar()
{
    while (janela->isOpen())
    {
        if(jogador->getPosition().x > fundoTelaTex.getSize().x) {
            janela->close();
        }
        janela->clear();
        gerenciadorGrafico->centralizar(jogador->getPosition());
        pausarJogada();
        verPontos();
        atualizar();
        render();
    }
}

int Fase::gerarAleatoriamente(int maior, int menor) {
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
    int aleatorio = rand()%(maior-menor+1) + menor;

    return aleatorio;
}
