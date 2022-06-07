#include "Ranking.h"

Ranking::Ranking(float largura, float altura) {
    if(!fonteRanking.loadFromFile("/Users/suzanabrasil/jogo/textura/Pacifico.ttf"))
        cout << "Não tem nenhuma fonte" << endl;
    // Listagem ranking
    // Le o arquivo arquivo.txt
    ifstream arq ("/Users/suzanabrasil/jogo/arquivo.txt");
    string linha;
    if(arq.is_open()) {
        int posicaoY = 50;
        int posicaoX = 100;
        int i = 0;
        while(getline(arq, linha)) {
            textoRanking[i].setFont(fonteRanking);
            textoRanking[i].setFillColor(Color::Black);
            textoRanking[i].setString(linha);
            textoRanking[i].setCharacterSize(40);
            textoRanking[i].setPosition(posicaoX, posicaoY);
            posicaoY += 50;
            i++;
            if(i%10 == 0) {
                posicaoX += 300;
                posicaoY = 50;
            }
        }
        maxRanking = i;
        arq.close();
    } else {
        cout << "Arquivo não está aberto" << endl;
    }
}
Ranking::~Ranking() {}

void Ranking::desenhar(RenderWindow& janela) {
    for(int i = 0; i < maxRanking; i++) {
        janela.draw(textoRanking[i]);
    }
}

string& Ranking::getNome() {
    return nome;
}

void Ranking::setNome(string& n) {
    nome = n;
}
