#include "Fase.h"
using namespace fases;


Fase::Fase(Jogador* j1, Jogador* j2, GerenciadorGrafico* gf) : Ente(), gerenciadorGrafico(gf), qtdJogadores(1), perdeu(false)
{
    id = 5;

    jogador1 = new Jogador();
    jogador2 = new Jogador();
    inicializarJogador(j1, j2);
    janela = gerenciadorGrafico->getJanela();
}

Fase::~Fase()
{
    delete jogador1;
    delete jogador2;
}

void Fase::inicializarPortal() {
    if (!portalTex.loadFromFile("texture/portal.png"))
    {
        printf("imagem não encontrada");
    }
    portal.setTexture(portalTex);
    portal.setScale(0.31f, 0.23f);
    portal.setPosition(fundoTelaTex.getSize().x - 620.f, 610.f);
}

void Fase::inicializarFundoTela(const char* caminho) {
    if(!fundoTelaTex.loadFromFile(caminho))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void Fase::renderFundoTela() {
    janela->draw(fundoTela);
    janela->draw(portal);
    janela->setFramerateLimit(60);
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
        salvarJogada();
        janela->close();
    }
}

void Fase::verPontos() {
    if(qtdJogadores == 1) {
        if(jogador1->getPontos() <= 0) {
            perdeu = true;
        }
    }
    else {
        if(jogador1->getPontos() <= 0 && jogador2->getPontos() > 0) {
            jogador1->desenhavel.move(0.0f, 1000.f);
        }
        else if (jogador1->getPontos() > 0 && jogador2->getPontos() <= 0)
            jogador2->desenhavel.move(0.0f, 1000.f);
        else if(jogador1->getPontos() <= 0 && jogador2->getPontos() <= 0) {
            perdeu = true;
        }
    }
}

void Fase::inicializarJogador(Jogador* j1, Jogador* j2)
{
    jogador1 = j1;
    jogador2 = j2;
    j1->inicializarTextura("texture/coelho2.png");
    j2->inicializarTextura("texture/coelho.png");
}

void Fase::atualizarJogador1()
{
    jogador1->atualizar1();
}

void Fase::atualizarJogador2() {
    jogador2->atualizar2();
}

void Fase::atualizar1()
{
    while (janela->pollEvent(event1))
    {
        if (event1.type == Event::Closed)
            janela->close();
        else if (event1.type == Event::KeyPressed && event1.key.code == Keyboard::Escape)
            janela->close();

        if(event1.type ==  Event::KeyReleased &&
            (event1.key.code == Keyboard::Escape || event1.key.code == Keyboard::Up ||
                 event1.key.code == Keyboard::Down || event1.key.code == Keyboard::Left
                    || event1.key.code == Keyboard::Right))
        {
            jogador1->resetTimerAnimacao();
        }
    }
    atualizarJogador1();
    atualizarColisao();
}

void Fase::atualizar2()
{
    while (janela->pollEvent(event2))
    {
        if (event2.type == Event::Closed)
            janela->close();
        else if (event2.type == Event::KeyPressed && event2.key.code == Keyboard::Escape)
            janela->close();

        if(event2.type ==  Event::KeyReleased &&
            (event2.key.code == Keyboard::Escape || event2.key.code == Keyboard::E ||
                 event2.key.code == Keyboard::D || event2.key.code == Keyboard::S
                    || event2.key.code == Keyboard::F))
        {
            jogador2->resetTimerAnimacao();
        }
    }
    atualizarJogador2();
    atualizarColisao();
}

void Fase::atualizarRenderJogador() {
    if(qtdJogadores == 1) {
        jogador1->render(*janela);
    }
    else {
        jogador1->render(*janela);
        jogador2->render(*janela);
    }
}

void Fase::atualizarColisao() {
    if(qtdJogadores == 1) {
        gerenciadorColisao.verificarColisoes(*janela, jogador1);
    }
    else {
        gerenciadorColisao.verificarColisoes(*janela, jogador1);
        gerenciadorColisao.verificarColisoes(*janela, jogador2);
    }
}

void Fase::render()
{
    renderFundoTela();
    atualizarRenderJogador();
    atualizarRenderObstaculos();
    atualizarRenderInimigos();

    janela->display();
    janela->setFramerateLimit(60);
}

int Fase::gerarAleatoriamente(int maior, int menor) {
    srand(time(NULL));
    int aleatorio = rand()%(maior-menor)+1 + menor;

    return aleatorio;
}

void Fase::setQtdJogadores(int qtd) {
    qtdJogadores = qtd;
}

int Fase::getQtdJogadores() {
    return qtdJogadores;
}

void Fase::setPerdeu(bool p) {
    perdeu = p;
}

bool Fase::getPerdeu() {
    return perdeu;
}

void Fase::executar() {
    janela->clear();
    gerenciadorGrafico->centralizar(jogador1->getPosition());
    pausarJogada();
    verPontos();
    if(qtdJogadores == 1) {
        atualizar1();
    }
    else {
        atualizar1();
        atualizar2();
    }
    render();
}
