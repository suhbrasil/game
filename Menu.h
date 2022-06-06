#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> // ofstream e ifstream
#include <string.h>
using namespace std;

#include "Pessoa.h"

class Menu
{
private:
    // Posição do menu
    int posicao;
    bool press, selecionado;
    sf::RenderWindow* janela;
    sf::RectangleShape* fecharJanela;
    sf::Font* fonte;
    sf::Texture* imagem;
    sf::Sprite* fundo;
    // Vetor para armazenas os nomes (opcoes para o jogo) que serão exibidos no menu
    std::vector<const char *> opcoes;
    std::vector<int> opcoesPos;
    std::vector<sf::Vector2f> coordOpcoes;
    std::vector<sf::Text> textos;
    // Tamanho da palavra
    std::vector<std::size_t> tamanho;

    // Cadastro jogador
    Pessoa pessoa;
public:
    Menu();
    ~Menu();
    void definirValores();
    // Armazenar os eventos do click do mouse, quando apertar alguma tecla, ...
    int loopEventos();
    // Desenhar tudo na tela
    void desenhar();

    void executar();
};
