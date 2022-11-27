#include "Jogo.h"
#include "conio.h"

GerenciadorEvento * Jogo::pEvento = GerenciadorEvento::getGerenciadorEvento();


Jogo::Jogo(): Ente(), 
    fase2(nullptr), 
    fase1(nullptr), 
    qJogadores(0),
    Jogador1(nullptr),
    Jogador2(nullptr),
    menu(nullptr)
{
    iniciarMenu();
    Executar();
}

Jogo::~Jogo()
{
    if(menu)
        delete menu;

    menu = nullptr;
    Jogador1 = nullptr;
    Jogador2 = nullptr;
}


void Jogo::iniciarMenu()
{
    std::cout << "Menu Principal iniciado." << std::endl;
    menu = new Menu();
}

void Jogo::iniciaFase1()
{
    Jogador1 = new Jogador(1);

    //if(qJogadores == 2) (TIRAR COMENTARIOS COM O MENU DE OPCOES IMPLEMENTADO)
        Jogador2 = new Jogador(2);

    pEvento->setJogador1(Jogador1);
    pEvento->setJogador2(Jogador2);

    fase1 = new Fase1(Jogador1, Jogador2);


    
}


void Jogo::deletaFase1()
{
    if (fase1 != nullptr)
        delete fase1;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO - FASE 1" << endl;

    fase1 = nullptr;
    Jogador1 = nullptr;
    Jogador2 = nullptr;
}

void Jogo::iniciaFase2()
{
    //CAso ja exista Jogadores
    if (Jogador1 && Jogador2) {

        Vector2<bool> jogadoresVivos;
        jogadoresVivos.x = Jogador1->getVida();
        jogadoresVivos.y = Jogador2->getVida();

        if (fase1) {
            cout << "TEMPO DE EXECUÇÃO FASE: " << fase1->tempoFase() << endl;
            deletaFase1();
        }

        if (jogadoresVivos.x == true)
            Jogador1 = new Jogador(1);

        if (jogadoresVivos.y == true)
            Jogador2 = new Jogador(2);
    }

    else {

        if (fase1) {
            cout << "TEMPO DE EXECUÇÃO FASE: " << fase1->tempoFase() << endl;
            deletaFase1();
        }

        Jogador1 = new Jogador(1);

        //if(qJogadores == 2) (TIRAR COMENTARIOS COM O MENU DE OPCOES IMPLEMENTADO)
            Jogador2 = new Jogador(2);

        //Zera os pontos
        Jogador1->setPontos(0, 0);
    }


    pEvento->setJogador1(Jogador1);
    pEvento->setJogador2(Jogador2);

    fase2 = new Fase2(Jogador1, Jogador2);
}

void Jogo::deletaFase2()
{
    if (fase2 != nullptr)
        delete fase2;
    else
        cout << "IMPOSSIVEL DELETAR PONTEIRO NULO - FASE 2" << endl;

    fase2 = nullptr;
    Jogador1 = nullptr;
    Jogador2 = nullptr;
}

/*    FUNCIONAMENTO DA FASE
*     Se há jogador vivo a fase continua.
*     Se a fase1 ja estiver acabada ou nao esta em execucao, a fase2 eh executada.
*     Quando instancia a fase2, se a fase1 existir ela eh deletada
*     Quando acabada a fase2 ela eh deletada
*     Quando os dois jogadores morrem, as duas fases se deletam
*/

void Jogo::controleFases()
{

    if (!fase1 && pGrafico->getEstado() == ID::fase1) {
        iniciaFase1();
        cout << "CRIEI FASE 1" << endl;
    }
    
    else if (!fase2 && pGrafico->getEstado() == ID::fase2) {
        iniciaFase2();
        cout << "CRIEI FASE 2" << endl;
    }

    else if (Jogador1 && Jogador1->getVida() == true || Jogador2 && Jogador2->getVida() == true) {

        if (fase1 && fase1->getAtiva())
        {
            fase1->Executar();
            fase1->verificaTerminoFase();
        }

        else
        {
            pGrafico->setEstado(ID::fase2);

            if (fase2)
            {
                if (fase2->getAtiva())
                {
                    fase2->Executar();
                    fase2->verificaTerminoFase();

                }
                else if (!fase2->getAtiva())
                {
                    cout << "GANHOOO JOGO! " << endl;

                    //Caso a fase termine, volta ao menu principal
                    pGrafico->setEstado(ID::menuPrincipal);
                    deletaFase2();

                    //PRECISA DEFINIR DE NOVO QUANTOS JOGADORES O USUARIO QUER CONTROLAR
                    qJogadores = 0;

                }
            }
        }
    }

    else {

        if (fase1)
            deletaFase1();
        if (fase2)
            deletaFase2();

        //Tela de gameOver
        cout << "FIM DO JOGO!" << endl; 

        //Tempo e uma imagem
        pGrafico->setEstado(ID::menuPrincipal);

        //PRECISA DEFINIR DE NOVO QUANTOS JOGADORES O USUARIO QUER CONTROLAR
        qJogadores = 0;
    }
}


void Jogo::Executar()
{
    
    //LOOP DE EXECUCAO DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        ID estado = pGrafico->getEstado();
        
        if (estado == ID::menuPrincipal)
        {
            menu->run_menu();
        }
        else if (estado == ID::menuPause)
        {

        }

        else if (estado == ID::menuQuantidadeJogadores)
        {
            //qJogadores = menu->run_menu_escolha (retorna um int de escolha)

        }

        else if (estado == ID::fase1 || estado == ID::fase2)
        {

            //if (qJogadores == 0)
                //pGrafico->setEstado(ID::menuQuantidadeJogadores);

            //else {
                pEvento->Executar();
                pGrafico->atualizaTempo();
                pGrafico->limpar();

                controleFases();

                pGrafico->mostrar();
            //}
        }
               
    }

}
