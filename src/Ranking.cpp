#include "Ranking.h"

Ranking::Ranking() : salvo(0), pontos(100) {
    inicializarFundoTela();
    inicializarTexto();
}
Ranking::~Ranking() {}

void Ranking::inicializarTexto() {
    if(!fonteRanking.loadFromFile("texture/Pacifico.ttf"))
        cout << "Não tem nenhuma fonte" << endl;

    // Listagem ranking
    // Le o arquivo arquivo.txt
    ifstream arq ("arquivo.txt");
    string linha;
    if(arq.is_open()) {
        int posicaoY = 50;
        int i = 0;
        while(getline(arq, linha)) {
            textoRanking[i].setFont(fonteRanking);
            textoRanking[i].setFillColor(Color::Black);
            textoRanking[i].setString(linha);
            textoRanking[i].setCharacterSize(35);
            textoRanking[i].setPosition(30, posicaoY);
            posicaoY += 50;
            i++;
        }
        maxRanking = i;
        arq.close();
    } else {
        cout << "Arquivo não está aberto" << endl;
    }
}

void Ranking::inicializarFundoTela() {
    if(!fundoTelaTex.loadFromFile("texture/ranking.jpg"))
        cout << "Erro: nao foi possivel carregar o background" << endl;
    fundoTela.setTexture(fundoTelaTex);
}

void Ranking::salvarPontos1(int p) {
    if(salvo) {
        // app = append (adiciona ao final do arquivo)
        ofstream ofs("arquivo.txt", fstream::app);
        ofs << nome1 << " ............................................................ " << p << " pontos" << "\n";
        ofs.close();
    }
}

void Ranking::salvarPontos2(int p1, int p2) {
    if(salvo) {
        // app = append (adiciona ao final do arquivo)
        ofstream ofs("arquivo.txt", fstream::app);
        ofs << nome1 << " ............................................................ " << p1 << " pontos" << "\n";
        ofs << nome2 << " ............................................................ " << p2 << " pontos" << "\n";
        ofs.close();
    }
}

void Ranking::salvarNome1() {
    cout << "Digite o nome do jogador: ";
    cin >> nome1;
    salvo = 1;
}

void Ranking::salvarNome2() {
    cout << "Digite o nome do jogador 1: ";
    cin >> nome1;
    cout << "Digite o nome do jogador 2: ";
    cin >> nome2;
    salvo = 1;
}

void Ranking::desenhar(RenderWindow& janela) {
    Event e;
    while(janela.isOpen()) {
        while(janela.pollEvent(e)) {
            if(e.type == Event::Closed) {
                janela.close();
            }
            if(e.type == Event::KeyPressed) {
                if(e.key.code == Keyboard::Escape)
                    janela.close();
            }
        }
        janela.clear();
        janela.draw(fundoTela);
        for(int i = 0; i < maxRanking; i++) {
            janela.draw(textoRanking[i]);
        }
        janela.display();
    }
}
