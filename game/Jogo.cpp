#include "Jogo.h"

Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento()), fase2(nullptr)
{

    //Alocando ele dinamic?mente (O NEW ? O EQUIVALENTE AO MALLOC EM C)
   
    iniciaFase1();
    Executar();
}

Jogo::~Jogo()
{
    //Jogador vai ser deletado na destrutora da lista

    Jogador1 = nullptr;
}



void Jogo::iniciaFase1()
{
    Jogador1 = new Jogador();
    pEvento->setJogador(Jogador1);

    fase1 = new Fase1(Jogador1);

}


void Jogo::deletaFase1()
{
    if (fase1 != nullptr)
        delete fase1;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO - FASE 1" << endl;

    fase1 = nullptr;
}

void Jogo::iniciaFase2()
{
    if(fase1)
        deletaFase1();

    Jogador1 = new Jogador();
    pEvento->setJogador(Jogador1);

    fase2 = new Fase2(Jogador1);
}

void Jogo::deletaFase2()
{
    if (fase2 != nullptr)
        delete fase2;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO - FASE 2" << endl;

    fase2 = nullptr;
    Jogador1 = nullptr;
}

void Jogo::controleFases()
{
    if (Jogador1 && Jogador1->getVida() == true) {

        if (fase1 && fase1->getAtiva())
        {
            fase1->Executar();
            fase1->verificaTerminoFase();
        }

        else
        {
            if (fase2 == nullptr)
                iniciaFase2();

            //cout << "Chamei a fase2" << endl;

            if (fase2->getAtiva()) {
                fase2->Executar();
                fase2->verificaTerminoFase();
            }
            else {
                deletaFase2();
            }
        }
    }
    else {

        if (fase1)
            deletaFase1();
        if (fase2)
            deletaFase2();

        //deletar
        cout << "FIM DO JOGO!" << endl; //tela de gameOver
        //tempo e uma imagem
        pGrafico->fecharJanela();
    }
}

void Jogo::Executar()
{
    
    //LOOP DE EXECU??O DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        pEvento->Executar();

        pGrafico->atualizaTempo();

        pGrafico->limpar();
  
        //Desenho as entidades da fase na tela e gerencio as colisoes entre elas dentro de cada fase
        controleFases();

        pGrafico->mostrar();
               
    }

}
