#include "Jogo.h"

Jogo::Jogo() : proximo(0)
{
    gerenciadorGrafico.inicializarJanela();
    inicializar();
}

Jogo::~Jogo()
{
    delete menu;
    delete faseUm;
    delete faseDois;
    delete ranking;
    delete jogador1;
    delete jogador2;
}
void Jogo::inicializar()
{
    jogador1 = new Jogador();
    jogador2 = new Jogador();
    faseUm = new FaseUm(jogador1, jogador2, &gerenciadorGrafico);
    faseDois = new FaseDois(jogador1, jogador2, &gerenciadorGrafico);
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

                    // Cadastro 1 jogador
                    if (x == 0)
                    {
                        faseUm->setQtdJogadores(1);
                        faseDois->setQtdJogadores(1);
                        ranking->salvarNome1();
                    }

                    // Cadastro 2 jogadores
                    if (x == 1)
                    {
                        faseUm->setQtdJogadores(2);
                        faseDois->setQtdJogadores(2);
                        ranking->salvarNome2();
                    }

                    // Fase 1
                    if(x == 2) {
                        while (gerenciadorGrafico.getJanela()->isOpen())
                        {
                            if(jogador1->getPosition().x > ((faseUm->getFundoTela().getSize().x) - 600) && !proximo) {
                                gerenciadorGrafico.getJanela()->clear();
                                gerenciadorGrafico.resetCamera();
                                jogador1->resetPosicao();
                                if(faseUm->getQtdJogadores() == 2)
                                    jogador2->resetPosicao();
                                proximo = 1;
                            }
                            else if(jogador1->getPosition().x > ((faseUm->getFundoTela().getSize().x) - 600) && proximo) {
                                menu->desenharGameOver(*gerenciadorGrafico.getJanela(), 0);
                            }
                            if(!faseUm->getPerdeu()) {
                                if(proximo)
                                    faseDois->executar();
                                else
                                    faseUm->executar();
                            }
                            else
                                menu->desenharGameOver(*gerenciadorGrafico.getJanela(), 1);
                        }
                    }

                    // Fase 2
                    if(x == 3) {
                        while (gerenciadorGrafico.getJanela()->isOpen())
                        {
                            if(!faseDois->getPerdeu()) {
                                if(jogador1->getPosition().x > ((faseUm->getFundoTela().getSize().x) - 600.f))
                                    menu->desenharGameOver(*gerenciadorGrafico.getJanela(), 0);
                                faseDois->executar();
                            }
                            else
                                menu->desenharGameOver(*gerenciadorGrafico.getJanela(), 1);
                        }
                    }

                    // Ranking
                    if(x == 4) {
                        ranking->desenhar(*gerenciadorGrafico.getJanela());
                    }

                    // Sair
                    if(x == 5)
                        gerenciadorGrafico.getJanela()->close();
                    break;
                }
            }
        }
        menu->desenhar(*gerenciadorGrafico.getJanela());
    }
    if(faseUm->getQtdJogadores() == 1)
         ranking->salvarPontos1(jogador1->getPontos());
    else {
        ranking->salvarPontos2(jogador1->getPontos(), jogador2->getPontos());
    }
}
