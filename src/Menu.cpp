/*
    Ifstream baseado no vídeo: https://www.youtube.com/watch?v=lzxWNtjii8U
*/

#include "Menu.h"

Menu::Menu(float largura, float altura) {
    if(!fonte.loadFromFile("/Users/suzanabrasil/jogo/textura/Pacifico.ttf"))
        cout << "Não tem nenhuma fonte" << endl;

    // Cadastrar jogador
    texto[0].setFont(fonte);
    texto[0].setFillColor(Color::Black);
    texto[0].setString("Cadastrar Jogador");
    texto[0].setCharacterSize(35);
    texto[0].setPosition(100, 150);

    // Fase 1
    texto[1].setFont(fonte);
    texto[1].setFillColor(Color::Black);
    texto[1].setString("Fase 1");
    texto[1].setCharacterSize(40);
    texto[1].setPosition(100, 250);

    // Fase 2
    texto[2].setFont(fonte);
    texto[2].setFillColor(Color::Black);
    texto[2].setString("Fase 2");
    texto[2].setCharacterSize(40);
    texto[2].setPosition(100, 350);

    // Ranking
    texto[3].setFont(fonte);
    texto[3].setFillColor(Color::Black);
    texto[3].setString("Ranking");
    texto[3].setCharacterSize(40);
    texto[3].setPosition(100, 450);

    // Sair
    texto[4].setFont(fonte);
    texto[4].setFillColor(Color::Black);
    texto[4].setString("Sair");
    texto[4].setCharacterSize(40);
    texto[4].setPosition(100, 550);

    selecionado = -1;
}

Menu::~Menu() {

}

void Menu::desenhar(RenderWindow& janela) {
    for(int i = 0; i < max_texto; i++) {
        janela.draw(texto[i]);
    }
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
        if(selecionado == 5) {
            selecionado = 0;
        }
        texto[selecionado].setFillColor(Color::White);
    }
}

int Menu::pressionado() {
    return selecionado;
}
