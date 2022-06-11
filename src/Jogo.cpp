#include "Jogo.h"

Jogo::Jogo() {
    gerenciadorGrafico.inicializarJanela();
    inicializar();

    // Background menu
    backgroundTextMenu.loadFromFile("texture/menu2.jpeg");
    gerenciadorGrafico.desenhar(&backgroundMenu, &backgroundTextMenu);

    // Background ranking
    backgroundTextRanking.loadFromFile("texture/ranking.jpg");
    gerenciadorGrafico.desenhar(&backgroundRanking, &backgroundTextRanking);
}

Jogo::~Jogo() {
    delete menu;
    delete faseUm;
    delete faseDois;
    delete ranking;

}
void Jogo::inicializar() {
    jogador = new Jogador();
    faseUm = new FaseUm(jogador, &gerenciadorGrafico);
    faseDois = new FaseDois(jogador, &gerenciadorGrafico);
    menu = new Menu();
    ranking = new Ranking();
}

void Jogo::executar() {
    while (gerenciadorGrafico.getJanela()->isOpen())
    {
        Event e;
        while (gerenciadorGrafico.getJanela()->pollEvent(e))
        {
            if (e.type == Event::Closed)
                gerenciadorGrafico.getJanela()->close();
            if (e.type == Event::KeyReleased)
            {
                if (e.key.code == Keyboard::Up)
                {
                    menu->MoverCima();
                    break;
                }
                if (e.key.code == Keyboard::Down)
                {
                    menu->MoverBaixo();
                    break;
                }
                if (e.key.code == Keyboard::Return)
                {
                    int x = menu->pressionado();

                    // Cadastro
                    if (x == 0)
                    {
                        ranking->salvarNome();
                    }

                    // Fase 1
                    if(x == 1) {
                        faseUm->executar();
                    }

                    // Fase 2
                    if(x == 2) {
                        faseDois->executar();
                    }

                    // Ranking
                    if(x == 3) {
                        while(gerenciadorGrafico.getJanela()->isOpen()) {
                            while(gerenciadorGrafico.getJanela()->pollEvent(e)) {
                                if(e.type == Event::Closed) {
                                    gerenciadorGrafico.getJanela()->close();
                                }
                                if(e.type == Event::KeyPressed) {
                                    if(e.key.code == Keyboard::Escape)
                                        gerenciadorGrafico.getJanela()->close();
                                }
                            }
                            gerenciadorGrafico.getJanela()->clear();
                            gerenciadorGrafico.getJanela()->draw(backgroundRanking);
                            ranking->desenhar(*gerenciadorGrafico.getJanela());
                            gerenciadorGrafico.getJanela()->display();
                        }
                    }

                    // Sair
                    if(x == 4)
                        gerenciadorGrafico.getJanela()->close();
                    break;
                }
            }
        }
        gerenciadorGrafico.getJanela()->clear();
        gerenciadorGrafico.getJanela()->draw(backgroundMenu);
        menu->desenhar(*gerenciadorGrafico.getJanela());
        gerenciadorGrafico.getJanela()->display();
    }
    ranking->salvarPontos(jogador->getPontos());
}
