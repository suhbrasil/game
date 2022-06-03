#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
private:
    // Posição do menu
    int posicao;
    bool press, selecionado;
    // Desenha a janela, variável criada como ponteiro para alocar memória
    sf::RenderWindow* janela;
    sf::RectangleShape* fecharJanela;
    // fonte das letras
    sf::Font* fonte;
    // Imagem de fundo do menu
    sf::Texture* imagem;
    // Sprite (espaço que será colocada a imagem) para a imagem
    sf::Sprite* fundo;
    // Vetor para armazenas os nomes (opcoes para o jogo) que serão exibidos no menu
    std::vector<const char *> opcoes;
    // Coordenadas das posicoes dos nomes
    std::vector<sf::Vector2f> coordOpcoes;
    // Vai renderizar os textos
    std::vector<sf::Text> textos;
    // Tamanho da palavra
    std::vector<std::size_t> tamanho;
public:
    Menu();
    ~Menu();
    void definirValores();
    // Armazenar os eventos do click do mouse, quando apertar alguma tecla, ...
    void loopEventos();
    // Desenhar tudo na tela
    void desenhar();
    void executar();
};
