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

    void salvarNome();
    void desenhar(RenderWindow& janela);
};
