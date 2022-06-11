#include "Ranking.h"

Ranking::Ranking() {
    pontos = 100;
    if(!fonteRanking.loadFromFile("texture/Pacifico.ttf"))
        cout << "Não tem nenhuma fonte" << endl;

    // Listagem ranking
    // Le o arquivo arquivo.txt
    ifstream arq ("/Users/suzanabrasil/jogo/arquivo.txt");
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
Ranking::~Ranking() {}

void Ranking::salvarPontos(int p) {
    pontos = p;

    // app = append (adiciona ao final do arquivo)
    ofstream ofs("arquivo.txt", fstream::app);
    ofs << nome << " ............................................................ " << pontos << " pontos" << "\n";
    ofs.close();
}

void Ranking::salvarNome() {
    cout << "Digite o nome da pessoa: ";
    cin >> nome;
}

void Ranking::desenhar(RenderWindow& janela) {
    for(int i = 0; i < maxRanking; i++) {
        janela.draw(textoRanking[i]);
    }
}
