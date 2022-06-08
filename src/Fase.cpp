#include "Fase.h"
using namespace fases;

Fase::Fase(Jogador* j)
{
    jogador = j;    
}

Fase::~Fase()
{
}

void Fase::atualizarJogador()
{
    jogador->atualizar();
}

void Fase::executar()
{

    if(event.type ==  Event::KeyReleased && 
        (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Up ||
            event.key.code == Keyboard::Down || event.key.code == Keyboard::Left 
            || event.key.code == Keyboard::Right))
            
        jogador->resetTimerAnimacao();
    
}

void Fase::atualizarRenderJogador() {
    //jogador->render(janela);
}

void Fase::atualizarColisao() {

    if(jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > janela->getSize().y) {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                janela->getSize().y - jogador->getGlobalBounds().height);
    }
}

