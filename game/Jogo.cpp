#include "Jogo.h"

Jogo::Jogo() : Ente(), pEvento(pEvento->getGerenciadorEvento())
{

    //Alocando ele dinamic�mente (O NEW � O EQUIVALENTE AO MALLOC EM C)
    
    Jogador1 = new Jogador();

    fase1 = new Fase(Jogador1);

    pEvento->setJogador(Jogador1);
    
    //CONHENCENDO A LISTA DE ENTIDADES
    lista_personagem = fase1->getListaPersonagem();
    lista_obstaculos = fase1->getListaObstaculo();

    pColisoes = new GerenciadorColisoes(lista_personagem, lista_obstaculos);

    Executar();
}

Jogo::~Jogo()
{
    //Jogador vai ser deletado na destrutora da lista

    delete fase1;
    delete pColisoes;

    lista_obstaculos = nullptr;
    lista_personagem = nullptr;
}

void Jogo::Executar()
{
    
    //LOOP DE EXECU��O DO PROGRAMA
    while (pGrafico->isWindowOpen())
    {
        pEvento->Executar();

        pGrafico->atualizaTempo();

        pGrafico->limpar();

        for (int j = 0; j < lista_obstaculos->listEnt.getTamanho(); j++)
        {
            Entidade* aux = lista_obstaculos->listEnt.getItemLista(j);
            aux->Executar();
            pGrafico->desenhar(aux->getCorpo());
        }

        //Implementar isso na classe da lista (se tiver tempo)
        for (int i = 0; i < lista_personagem->listEnt.getTamanho(); i++)
        {
            
            //colocar uma condicao de id aqui(se for personagem dar o static_cast, se nao, deixar o aux como entidade)
            Personagens* aux = static_cast<Personagens*>(lista_personagem->listEnt.getItemLista(i));
            if (aux->getVida() == true) {
                aux->Executar();
                pGrafico->desenhar(aux->getCorpo());
            }
            else {
                //cout << "O PERSONAGEM ESTA MORTO" << endl;
            }
      
        }
        
        
        
        pColisoes->verificaColisoes();

        pGrafico->mostrar();
               
    }

}
