#include "GerenciadorGrafico.h"

#define RESOLUCAO_X 1280
#define RESOLUCAO_Y 720


GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;
float GerenciadorGrafico::dt = 0;

GerenciadorGrafico::GerenciadorGrafico(): estado(ID::menuPrincipal),
    window(new sf::RenderWindow(sf::VideoMode(RESOLUCAO_X, RESOLUCAO_Y), "Jogo")),
    clock()
{
    if (window == nullptr) {
        std::cout << "Nao foi possivel criar uma janela gráfica!" << std::endl;
        exit(1);
    }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window) {
        delete(window);
        window = nullptr;
    }

}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGrafico == nullptr) {
        pGrafico = new GerenciadorGrafico;
    }

    return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::limpar()
{
    window->clear();
}

void GerenciadorGrafico::desenhar(sf::RectangleShape corpo)
{
    window->draw(corpo);
}

/*
void GerenciadorGrafico::desenhar(sf::Sprite p)
{
    window->draw(p);
}

void GerenciadorGrafico::desenhar(sf::Text t)
{
    window->draw(t);
}
*/
void GerenciadorGrafico::mostrar()
{
    window->display();
}

void GerenciadorGrafico::fecharJanela()
{
    window->close();
}

const bool GerenciadorGrafico::isWindowOpen()
{
    return window->isOpen();
}


void GerenciadorGrafico::atualizaTempo()
{
    dt = clock.getElapsedTime().asSeconds();
    clock.restart();

}

void GerenciadorGrafico::setEstado(const ID id)
{
    estado = id;
}

const ID GerenciadorGrafico::getEstado() const
{
    return estado;
}

