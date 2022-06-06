#include "Menu.h"

Menu::Menu()
{
    // Alocar todos
    janela = new sf::RenderWindow();
    fecharJanela = new sf::RectangleShape();
    fonte = new sf::Font();
    imagem = new sf::Texture();
    fundo = new sf::Sprite();

    definirValores();
}

Menu::~Menu()
{
    delete janela;
    delete fecharJanela;
    delete fonte;
    delete imagem;
    delete fundo;
}

void Menu::definirValores()
{
    // Video mode é o tamanho da janela que irá criar e
    // 2250 e 1400
    janela->create(sf::VideoMode(1400, 1525), "Menu jogo");
    // Posição inicial que irá abrir a janelalkkokk;lll
    janela->setPosition(sf::Vector2i(0, 0));

    posicao = 0;
    press = false;
    selecionado = false;

    // Carregar fonte do texto e a imagem de fundo do menu
    fonte->loadFromFile("/Users/suzanabrasil/jogo/textura/Pacifico.ttf");
    imagem->loadFromFile("/Users/suzanabrasil/jogo/textura/menu.png");

    // Definir a imagem como a textura de fundo
    fundo->setTexture(*imagem);

    opcoes = {"Ranking" ,"Fase 2", "Fase 1", "Cadastrar Jogador"};
    opcoesPos = {0, 1, 2, 3};
    // Resize atualiza o tamanho do vetor para o tamanho passado como parâmtro
    // Resize está sendo usado para se acontecer alguma falha de segmentação
    textos.resize(4);
    coordOpcoes = {{470, 900}, {520, 700}, {520, 500}, {300, 300}};
    tamanho = {80, 80, 80, 70};

    for (std::size_t i{}; i < textos.size(); ++i)
    {
        // Definir a fonte do texto
        textos[i].setFont(*fonte);
        // Definir qual é o texto que será escrito
        textos[i].setString(opcoes[i]);
        // Definir o tamanho do texto
        textos[i].setCharacterSize(tamanho[i]);
        // Definir cor do texto
        textos[i].setOutlineColor(sf::Color::Black);
        // Definir a posicao do texto
        textos[i].setPosition(coordOpcoes[i]);
    }
    textos[3].setOutlineThickness(8);
    posicao = 3;
}

int Menu::loopEventos()
{
    sf::Event e;
    // Verifica se a janela está dando algum evento e recupera ele
    while (janela->pollEvent(e))
    {
        // Se o evento recuperado da janela for para fechá-la
        if (e.type == sf::Event::Closed)
            janela->close();

        // Verifica se a tecla para baixo do teclado está pressionada
        // !press verifica se ela já não estava pressionada antes, pois iria ficar indo para baixo sem parar
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !press)
        {
            if (posicao < 3)
            {
                posicao++;
                press = true;
                // coloca uma espessura no texto que está sendo selecionado pelo teclado
                textos[posicao].setOutlineThickness(8);
                // tira a espessura que tinha sido colocada no texto que estava selecionado antes, pois a espessura não sai sozinha
                textos[posicao - 1].setOutlineThickness(0);
                press = false;
                selecionado = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !press)
        {
            if (posicao > 0)
            {
                posicao--;
                press = true;
                textos[posicao].setOutlineThickness(8);
                textos[posicao + 1].setOutlineThickness(0);
                press = false;
                selecionado = false;
            }
        }

        // Se clicar em enter e não estiver selecionado (evita de poder dar enter várias vezes)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !selecionado)
        {
            selecionado = true;
            std::cout << opcoes[posicao] << std::endl;
            return opcoesPos[posicao];
        }
    }
}

void Menu::desenhar()
{
    // limpar a janela
    janela->clear();
    janela->draw(*fundo);
    // auto pega o tipo da variável que está sendo declarada
    for (auto t : textos) {
        janela->draw(t);
    }
    janela->display();
}

void Menu::executar()
{
    int pos;
    while (janela->isOpen())
    {
        pos = loopEventos();
        desenhar();
        if(pos == 3) {
            string nome;
            // app = append (adiciona ao final do arquivo)
            ofstream ofs("arquivo.txt", fstream::app);
            cout << "Digite o nome da pessoa: ";
            cin >> nome;
            cout << endl;

            pessoa.setNome(nome);

            // salva o nome da pessoa no arquivo
            ofs << pessoa;
            ofs.close();
        }
    }
}
