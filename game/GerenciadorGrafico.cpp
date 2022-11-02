#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;


GerenciadorGrafico::GerenciadorGrafico():
    window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Jogo"))
{
    if (window == nullptr) {
        std::cout << "Nao foi possivel criar uma janela gr�fica!" << std::endl;
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
        return pGrafico = new GerenciadorGrafico;
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