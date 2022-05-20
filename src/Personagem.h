#include <SFML/Graphics.hpp>

namespace exercicio {
    class Personagem
    {
    private:
        sf::Texture* text;
        sf::RectangleShape corpo;
        float x, y;
    public:
        Personagem(float xInicial = 0.0f, float yInicial = 0.0f, const char* caminhoTextura = nullptr);
        ~Personagem();
        void atualizar();
        void desenhar(sf::RenderWindow* janela);
    };
}
