#include "FaseUm.h"
using namespace fases;


FaseUm::FaseUm(Jogador* j) : Fase(j)
{
    inicializarFundoTela();
    inicializarBotaoPausar();
    inicializarJogador(j);
    qtdeGalhos = gerarAleatoriamente(3);
    qtdeEspinhos = gerarAleatoriamente(3);
    gerarObstaculos();
}

FaseUm::~FaseUm()
{
}

void FaseUm::inicializarJanela()
{
    janela.create(sf::VideoMode(1200, 700), "FaseUm", sf::Style::Close | sf::Style::Titlebar);
    // limita a taxa de atualização da tela
    janela.setFramerateLimit(60);
}

const RenderWindow& FaseUm::getJanela() const
{
    return janela;
}

void FaseUm::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("texture/background.jpeg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void FaseUm::renderFundoTela() {
    janela.draw(fundoTela);
    janela.draw(texto);
}

void FaseUm::inicializarBotaoPausar() {
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

void FaseUm::salvarJogada() {
    ofstream arq("jogada.txt", fstream::app);
    arq << jogador->getPosition().x << "\n" << jogador->getPosition().y << "\n";
    arq.close();
}

void FaseUm::pausarJogada() {
    posMouse = sf::Mouse::getPosition(janela);
    // Mapear as coordenadas da posicao do mouse
    coordMouse = janela.mapPixelToCoords(posMouse);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(texto.getGlobalBounds().contains(coordMouse)) {
            salvarJogada();
            janela.close();
        }
    }
}

void FaseUm::inicializarJogador(Jogador* j)
{
    jogador = new Jogador();
    jogador = j;
}


void FaseUm::atualizarJogador()
{
    jogador->atualizar();
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
    galho->render(janela);

}

void FaseUm::atualizarRenderEspinhos(int j) {
    Espinho* espinho = dynamic_cast <Espinho*>(espinhos.lista.getItem(j)->getInfo());
    espinho->render(janela);
}

void FaseUm::atualizarRenderObstaculos() {
    for (int i = 0 ; i < qtdeGalhos; i++){
       atualizarRenderGalhos(i);
    }

    for (int j = 0 ; j < qtdeEspinhos; j++){
       atualizarRenderEspinhos(j);
    }
}

void FaseUm::atualizar()
{
    while (janela.pollEvent(event))
    {
        if (event.type == Event::Closed)
            janela.close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            janela.close();

        if(event.type ==  Event::KeyReleased &&
            (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Up ||
                 event.key.code == Keyboard::Down || event.key.code == Keyboard::Left
                    || event.key.code == Keyboard::Right))
            jogador->resetTimerAnimacao();
    }

    atualizarJogador();
    atualizarColisao();
}

void FaseUm::atualizarRenderJogador() {
    jogador->render(janela);
}

void FaseUm::atualizarColisao() {
    gerenciadorColisao.verificarColisoes(janela, jogador);
}

void FaseUm::render()
{
    // Desenhar fundo de tela
    renderFundoTela();
    atualizarRenderJogador();
    atualizarRenderObstaculos();

    janela.display();
}

void FaseUm::executar()
{
    inicializarJanela();
    while (janela.isOpen())
    {
        janela.clear();
        pausarJogada();
        atualizar();
        render();
    }
}
