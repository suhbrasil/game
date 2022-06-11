#include "Fase.h"
using namespace fases;


Fase::Fase(Jogador* j, GerenciadorGrafico* gf) : gerenciadorGrafico(gf)
{
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


void Fase::inicializarBotaoPausar() {
    if(!fonte.loadFromFile("texture/Pacifico.ttf"))
        cout << "Não tem nenhuma fonte" << endl;

    // Botao salvar
    texto.setFont(fonte);
    texto.setFillColor(Color::White);
    texto.setString("Pausar");
    texto.setCharacterSize(30);
    texto.setPosition(10, 10);

    posMouse = {0,0};
    coordMouse = {0.0f,0.0f};
}

void Fase::salvarJogada() {
    ofstream arq("jogada.txt", fstream::app);
    arq << jogador->getPosition().x << "\n" << jogador->getPosition().y << "\n";
    arq.close();
}

void Fase::pausarJogada() {
    inicializarBotaoPausar();
    posMouse = sf::Mouse::getPosition(*janela);
    // Mapear as coordenadas da posicao do mouse
    coordMouse = janela->mapPixelToCoords(posMouse);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(texto.getGlobalBounds().contains(coordMouse)) {
            salvarJogada();
            janela->close();
        }
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
