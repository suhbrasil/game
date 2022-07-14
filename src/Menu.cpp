#include "Menu.h"

Menu::Menu() : Ente() {
    id = 12;

    inicializarFundoTela();
    inicializarTextoMenu();

    selecionado = -1;
}

Menu::~Menu() {

}

void Menu::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("texture/menu2.jpeg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}


void Menu::inicializarTextoMenu() {
    if(!fonte.loadFromFile("texture/Pacifico.ttf"))
        cout << "Não tem nenhuma fonte" << endl;

    // Cadastrar jogador 1
    texto[0].setFont(fonte);
    texto[0].setFillColor(Color::Black);
    texto[0].setString("Cadastrar 1 jogador");
    texto[0].setCharacterSize(35);
    texto[0].setPosition(100, 100);

    // Cadastrar jogador 2
    texto[1].setFont(fonte);
    texto[1].setFillColor(Color::Black);
    texto[1].setString("Cadastrar 2 jogadores");
    texto[1].setCharacterSize(35);
    texto[1].setPosition(100, 200);

    // Fase 1
    texto[2].setFont(fonte);
    texto[2].setFillColor(Color::Black);
    texto[2].setString("Fase 1");
    texto[2].setCharacterSize(40);
    texto[2].setPosition(100, 300);

    // Fase 2
    texto[3].setFont(fonte);
    texto[3].setFillColor(Color::Black);
    texto[3].setString("Fase 2");
    texto[3].setCharacterSize(40);
    texto[3].setPosition(100, 400);

    // Ranking
    texto[4].setFont(fonte);
    texto[4].setFillColor(Color::Black);
    texto[4].setString("Ranking");
    texto[4].setCharacterSize(40);
    texto[4].setPosition(100, 500);

    // Sair
    texto[5].setFont(fonte);
    texto[5].setFillColor(Color::Black);
    texto[5].setString("Sair");
    texto[5].setCharacterSize(40);
    texto[5].setPosition(100, 600);
}

void Menu::inicializarTextoGameOver() {
     if(!fonteGameOver.loadFromFile("texture/GameOfSquids.ttf"))
        cout << "Não tem nenhuma fonte" << endl;

    // Game Over
    textoGameOver.setFont(fonteGameOver);
    textoGameOver.setFillColor(Color::White);
    textoGameOver.setString("Game Over");
    textoGameOver.setCharacterSize(50);
    textoGameOver.setPosition(400, 200);
}

void Menu::MoverCima() {
    if(selecionado - 1 >= 0) {
        // Se o botão estava branco deixa preto de volta
        texto[selecionado].setFillColor(Color::Black);
        selecionado--;
        if(selecionado == -1) {
            selecionado = 2;
        }
        // Botão selecionado ficará branco
        texto[selecionado].setFillColor(Color::White);
    }
}

void Menu::MoverBaixo() {
    if(selecionado + 1 <= max_texto) {
        texto[selecionado].setFillColor(Color::Black);
        selecionado++;
        if(selecionado == max_texto) {
            selecionado = 0;
        }
        texto[selecionado].setFillColor(Color::White);
    }
}


int Menu::pressionado() {
    return selecionado;
}

void Menu::desenhar(RenderWindow& janela) {
    janela.clear();
    janela.draw(fundoTela);
    for(int i = 0; i < max_texto; i++) {
        janela.draw(texto[i]);
    }
    janela.display();
}

void Menu::desenharGameOver() {
    gameOver.create(sf::VideoMode(1200, 700), "Game Over", sf::Style::Close | sf::Style::Titlebar);
    while(gameOver.isOpen()) {
        inicializarTextoGameOver();
        Event e;
        while (gameOver.pollEvent(e))
        {
            if (e.type == Event::Closed)
                gameOver.close();
            else if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
                gameOver.close();
            gameOver.clear();
            gameOver.draw(textoGameOver);
            gameOver.display();
        }
    }
}
