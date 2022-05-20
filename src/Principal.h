#include <SFML/Graphics.hpp>

#include "Personagem.h"

namespace exercicio {
    class Principal
    {
    private:
        sf::RenderWindow* janela;
        Personagem amigo;
    public:
        Principal();
        ~Principal();
        int executar();
    };
}
