#include <SFML/Graphics.hpp>
#include <fstream> // ofstream e ifstream
#include <iostream>
#include <string.h>
using namespace std;
using namespace sf;

#define max_ranking 100

class Ranking
{
private:
    string nome;

    // Texto ranking
    Font fonteRanking;
    Text textoRanking[max_ranking];
    int maxRanking;
public:
    Ranking(float largura = 0.0f, float altura = 0.0f);
    ~Ranking();

    string& getNome() { return nome; }
    void setNome(string& n) { nome = n; }

    // sobrecarga do operador de fluxo de saída
    // a função friend retorna uma refência para "ostream" que é uma das classes definidas em "iostream.h"
    friend ostream& operator<<(ostream& os, const Ranking& dados) {
        // os é uma referência a "ostream"
         os << dados.nome << "\n";
        return os;
    }

    void desenhar(RenderWindow& janela);
};
