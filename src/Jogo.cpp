#include "Jogo.h"

Jogo::Jogo() : proximo(0) {
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

    pilha.push(faseDois);
    pilha.push(faseUm);
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
                        while (gerenciadorGrafico.getJanela()->isOpen())
                        {
                            if(jogador->getPosition().x > faseUm->getFundoTela().getSize().x && !proximo) {
                                gerenciadorGrafico.getJanela()->clear();
                                gerenciadorGrafico.resetCamera();
                                jogador->resetPosicao();
                                proximo = 1;
                            }
                            else if(jogador->getPosition().x > faseUm->getFundoTela().getSize().x && proximo)
                                gerenciadorGrafico.getJanela()->close();
                            if(proximo)
                                faseDois->executar();
                            else
                                faseUm->executar();
                        }
                    }

                    // Fase 2
                    if(x == 2) {
                        while (gerenciadorGrafico.getJanela()->isOpen())
                        {
                            if(jogador->getPosition().x > faseUm->getFundoTela().getSize().x)
                                gerenciadorGrafico.getJanela()->close();
                            faseDois->executar();
                        }
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


// while (gerenciadorGrafico.getJanela()->isOpen())
    // {
    //     Event e;
    //     while (gerenciadorGrafico.getJanela()->pollEvent(e))
    //     {
    //         if (e.type == Event::Closed)
    //             gerenciadorGrafico.getJanela()->close();
    //         if (e.type == Event::KeyReleased)
    //         {
    //             if (e.key.code == Keyboard::Up)
    //             {
    //                 menu->MoverCima();
    //                 break;
    //             }
    //             if (e.key.code == Keyboard::Down)
    //             {
    //                 menu->MoverBaixo();
    //                 break;
    //             }
    //             if (e.key.code == Keyboard::Return)
    //             {
    //                 int x = menu->pressionado();

    //                 // Cadastro
    //                 if (x == 0)
    //                 {
    //                     ranking->salvarNome();
    //                 }

    //                 // Fase 1
    //                 if(x == 1) {
    //                     faseUm->executar();
    //                 }

    //                 // Fase 2
    //                 if(x == 2) {
    //                     faseDois->executar();
    //                 }

    //                 // Ranking
    //                 if(x == 3) {
    //                     while(gerenciadorGrafico.getJanela()->isOpen()) {
    //                         while(gerenciadorGrafico.getJanela()->pollEvent(e)) {
    //                             if(e.type == Event::Closed) {
    //                                 gerenciadorGrafico.getJanela()->close();
    //                             }
    //                             if(e.type == Event::KeyPressed) {
    //                                 if(e.key.code == Keyboard::Escape)
    //                                     gerenciadorGrafico.getJanela()->close();
    //                             }
    //                         }
    //                         gerenciadorGrafico.getJanela()->clear();
    //                         gerenciadorGrafico.getJanela()->draw(backgroundRanking);
    //                         ranking->desenhar(*gerenciadorGrafico.getJanela());
    //                         gerenciadorGrafico.getJanela()->display();
    //                     }
    //                 }

    //                 // Sair
    //                 if(x == 4)
    //                     gerenciadorGrafico.getJanela()->close();
    //                 break;
    //             }
    //         }
    //     }
    //     gerenciadorGrafico.getJanela()->clear();
    //     gerenciadorGrafico.getJanela()->draw(backgroundMenu);
    //     menu->desenhar(*gerenciadorGrafico.getJanela());
    //     gerenciadorGrafico.getJanela()->display();
    // }
    // ranking->salvarPontos(jogador->getPontos());
