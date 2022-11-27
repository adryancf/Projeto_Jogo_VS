#include "GerenciadorEventos.h"

#define TAM_PULO_JOGADOR 0.003f

GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

GerenciadorEvento::GerenciadorEvento():
    pGrafico(GerenciadorGrafico::getGerenciadorGrafico()), 
    Jogador1(nullptr),
    Jogador2(nullptr),
    tecla_pres(0)
{
}

GerenciadorEvento::~GerenciadorEvento()
{
    if (pEvento) {
        delete(pEvento);
        pEvento = nullptr;
    }
    if (pGrafico) {
        delete(pGrafico);
        pGrafico = nullptr;
    }
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
{
    if (pEvento == nullptr) {
        return pEvento = new GerenciadorEvento;
    }

    return pEvento;
}

void GerenciadorEvento::setJogador1(Jogador* j)
{
    this->Jogador1 = j;
}

void GerenciadorEvento::setJogador2(Jogador* j)
{
    this->Jogador2 = j;
}

void GerenciadorEvento::verificaTeclaPressionada()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        pGrafico->fecharJanela();
    }

    //CONTROLE JOGADOR 1
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Jogador1 != nullptr) {
        Jogador1->andar(2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Jogador1 != nullptr) {
        Jogador1->andar(4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Jogador1 != nullptr) {
        Jogador1->pular(TAM_PULO_JOGADOR);
    }

    //CONTROLE JOGADOR 2
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Jogador2 != nullptr) {
        Jogador2->andar(2);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Jogador2 != nullptr) {
        Jogador2->andar(4);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Jogador2 != nullptr) {
        Jogador2->pular(TAM_PULO_JOGADOR);
    }   
}

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
    if (tecla == sf::Keyboard::Escape) {
        pGrafico->fecharJanela();
    }

    //CONTROLE JOGADOR 1
    if (tecla == sf::Keyboard::A && Jogador1 != nullptr) {
        Jogador1->andar(2);
        tecla_pres = 1;
    }
    else if (tecla == sf::Keyboard::D && Jogador1 != nullptr) {
        Jogador1->andar(4);
        tecla_pres = 2;
    }
    if (tecla == sf::Keyboard::W && Jogador1 != nullptr) {
        Jogador1->pular(TAM_PULO_JOGADOR);
    }

    //CONTROLE JOGADOR 2
    if (tecla == sf::Keyboard::Left && Jogador2 != nullptr) {
        Jogador2->andar(2);
        tecla_pres = 1;
    }
    else if (tecla == sf::Keyboard::Right && Jogador2 != nullptr) {
        Jogador2->andar(4);
        tecla_pres = 2;
    }

    else if (tecla == sf::Keyboard::Space && Jogador2 != nullptr) {
        Jogador2->pular(TAM_PULO_JOGADOR);
    }
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    //VERIFICAR SE A TECLA FOR SOLTA E ALTERAR A FLAG
    
    if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D)
        Jogador1->setAndando(false);
        
    else if(tecla == sf::Keyboard::Right || tecla == sf::Keyboard::Left)
        Jogador2->setAndando(false);
}

void GerenciadorEvento::Executar()
{
    //loop de execu��o da janela
    
    Event event;
    while (pGrafico->getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            verificaTeclaPressionada(event.key.code);

            
        }

        else if (event.type == Event::KeyReleased) {
            verificaTeclaSolta(event.key.code);
        }
        else if (event.type == Event::Closed) {
            pGrafico->fecharJanela();
        } 

    }

}
