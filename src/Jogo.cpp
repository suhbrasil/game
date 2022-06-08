#include "Jogo.h"

Jogo::Jogo()
{
    gerenciadorGrafico.inicializarJanela();
    menu = new Menu();
    ranking = new Ranking();
    // Background menu
    backgroundTextMenu.loadFromFile("/Users/suzanabrasil/jogo/textura/menu2.jpeg");
    gerenciadorGrafico.desenhar(&backgroundMenu, &backgroundTextMenu);


    // Background JOGO
    backgroundText.loadFromFile("/Users/suzanabrasil/jogo/textura/background.jpeg");
    gerenciadorGrafico.desenhar(&background, &backgroundText);

    // Background ranking
    backgroundTextRanking.loadFromFile("/Users/suzanabrasil/jogo/textura/ranking.jpg");
    gerenciadorGrafico.desenhar(&backgroundRanking, &backgroundTextRanking);


    inicializarJogador();
}

Jogo::~Jogo()
{
    delete jogador;
}

void Jogo::inicializarJogador()
{
    jogador = new Jogador();
}

void Jogo::atualizarJogador()
{
    jogador->atualizar();
}

void Jogo::atualizar()
{
    while (gerenciadorGrafico.getJanela().pollEvent(event))
    {
        if (event.type == Event::Closed)
            gerenciadorGrafico.getJanela().close();
        else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            gerenciadorGrafico.getJanela().close();

        if (event.type == Event::KeyReleased &&
            (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Up ||
             event.key.code == Keyboard::Down || event.key.code == Keyboard::Left || event.key.code == Keyboard::Right))

            jogador->resetTimerAnimacao();
    }

    atualizarJogador();
    atualizarColisao();
}

void Jogo::atualizarRenderJogador()
{
    jogador->render(gerenciadorGrafico.getJanela());
}

void Jogo::atualizarColisao()
{
    if (jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > gerenciadorGrafico.getJanela().getSize().y)
    {
        jogador->resetVelocidadeY();
        jogador->setPosition(jogador->getGlobalBounds().left,
                             gerenciadorGrafico.getJanela().getSize().y - jogador->getGlobalBounds().height);
    }
}

void Jogo::render()
{
    atualizarRenderJogador();
    gerenciadorGrafico.getJanela().setFramerateLimit(60);
}

void Jogo::executar()
{
    while (gerenciadorGrafico.getJanela().isOpen())
    {
        Event e;
        while (gerenciadorGrafico.getJanela().pollEvent(e))
        {
            if (e.type == Event::Closed)
                gerenciadorGrafico.getJanela().close();
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
                    RenderWindow FASE2(VideoMode(1280, 720), "Fase 2");
                    // RenderWindow RANKING(VideoMode(1280, 720), "Ranking");

                    int x = menu->pressionado();
                    // Cadastro
                    if (x == 0)
                    {
                        string nome;
                        // app = append (adiciona ao final do arquivo)
                        ofstream ofs("arquivo.txt", fstream::app);
                        cout << "Digite o nome da pessoa: ";
                        cin >> nome;
                        cout << endl;

                        ranking->setNome(nome);

                        ofs << *ranking;
                        ofs.close();
                    }
                    // Fase 1
                    if(x == 1) {
                        while(gerenciadorGrafico.getJanela().isOpen()) {
                            gerenciadorGrafico.getJanela().clear();
                            FASE2.close();
                            atualizar();
                            gerenciadorGrafico.getJanela().draw(background);
                            render();
                            gerenciadorGrafico.getJanela().display();
                        }
                    }
                    if(x == 2) {
                        while(FASE2.isOpen()) {
                            Event f2e;
                            while(FASE2.pollEvent(f2e)) {
                                if(f2e.type == Event::Closed) {
                                    FASE2.close();
                                }
                                if(f2e.type == Event::KeyPressed) {
                                    if(f2e.key.code == Keyboard::Escape)
                                        FASE2.close();
                                }
                            }
                            FASE1.close();
                            FASE2.clear();
                            FASE2.display();
                        }
                    }
                    if(x == 3) {
                        while(gerenciadorGrafico.getJanela().isOpen()) {
                            while(gerenciadorGrafico.getJanela().pollEvent(e)) {
                                if(e.type == Event::Closed) {
                                    gerenciadorGrafico.getJanela().close();
                                }
                                if(e.type == Event::KeyPressed) {
                                    if(e.key.code == Keyboard::Escape)
                                        gerenciadorGrafico.getJanela().close();
                                }
                            }
                            // FASE1.close();
                            FASE2.close();
                            gerenciadorGrafico.getJanela().clear();
                            gerenciadorGrafico.getJanela().draw(backgroundRanking);
                            ranking->desenhar(gerenciadorGrafico.getJanela());
                            gerenciadorGrafico.getJanela().display();
                        }
                    }
                    if(x == 4)
                        gerenciadorGrafico.getJanela().close();
                    break;
                }
            }
        }
        gerenciadorGrafico.getJanela().clear();
        gerenciadorGrafico.getJanela().draw(backgroundMenu);
        menu->desenhar(gerenciadorGrafico.getJanela());
        gerenciadorGrafico.getJanela().display();
    }
}
