#include "Jogador.h"



Jogador::Jogador():Personagens(), tempo()
{
    setVelocidade(Vector2f(10.f, 0.f));
    ID = 1;
}

void Jogador::iniciar()
{

}
Jogador::~Jogador(){}

void Jogador::Mover()
{
    
    //Representar quando ele ta parado
    olhandoDireita = false;
    olhandoEsquerda = false;

    movGravidade();
}

void Jogador::Executar()
{
    verificaVida();
    Mover();
}

/* OS GERENCIADORES QUE CHAMAM ESSAS FUN��ES */

//GERENCIADOR DE EVENTOS
void Jogador::andar(int i)
{
    speed.x = 10.f;

    verificaPodeAndar(speed);

    if (i == 2 && podeAndarEsquerda)
    {
        corpo.move(Vector2f(-speed.x, 0));
        olhandoEsquerda = true;
        olhandoDireita = false;
    }
    else if (i == 4 && podeAndarDireita)
    {
        corpo.move(Vector2f(speed.x, 0));
        olhandoDireita = true;
        olhandoEsquerda = false;
    }
}

//GERENCIADOR DE COLIS�ES
void Jogador::Colisao(Entidade* entidade, Vector2f inter_colisao)
{

    float t = tempo.getElapsedTime().asSeconds();

    int id_entidade = entidade->getId();
    Vector2<bool> olhar_entidade;

    corrigeColisoes(entidade, inter_colisao);
   
    //Plataforma (Nao precisa disso pois ele ja corrige a colisao, entao nao preciso tirar a gravidade) -> PENSAR MELHOR
    //verificaColisaoPlataforma(entidade);
    
    //Dragao -> joga pta cima e pro lado a cada 1.5 segundos
    if (id_entidade == 10)
    {
        Vector2f repulsao(0.0, 0.0);
        Dragao* dragao = static_cast<Dragao*>(entidade);
        olhar_entidade = dragao->getOlhar();

        if (!emCima) 
        {
           
            if (olhandoDireita || olhar_entidade.y)
            {
                repulsao.x = -80.0;

                verificaPodeAndar(repulsao);
                dragao->verificaPodeAndar(repulsao);

                if (podeAndarEsquerda == true)
                {
                    corpo.move(repulsao);
                    //dragao->movimentaEntidade(Vector2f(40.0, 0.0f));
                }
            }

            else if (olhandoEsquerda || olhar_entidade.x)
            {
                repulsao.x = 80.0;

                verificaPodeAndar(repulsao);
                dragao->verificaPodeAndar(repulsao);

                if (podeAndarDireita == true)
                {
                    corpo.move(repulsao);
                    //dragao->movimentaEntidade(Vector2f(-40.0, repulsao.y));

                }
            }
          
            else
                cout << "NAO DA PRA SE MOVER" << endl;

            //Nao esta funcionando (nao to entendendo)
            //pular(0.05);

            //perdeVida();

            dragao->perdeVida();
            tempo.restart();
        }
    }

    
    //Hydra
    else if (id_entidade == 15)
    {
        Vector2f repulsao(15.0, 0.0);

        Personagens* hydra = static_cast<Personagens*>(entidade);
        olhar_entidade = hydra->getOlhar();

        // Come�a a perseguir o jogador
        hydra->setAtacou(true);

        //Se o jogador ta em cima dela, ela perde vida
        if (emCima)
        {
            hydra->perdeVida();
        }
        else
        {
            if (olhandoDireita || olhar_entidade.y)
            {
                repulsao.x = -15.0;
                verificaPodeAndar(repulsao);

                if (podeAndarEsquerda)
                    corpo.move(repulsao);
                else
                    hydra->setAtacou(false);
            }


            else if (olhandoEsquerda || olhar_entidade.x)  {
                repulsao.x = 15.0;
                verificaPodeAndar(repulsao);

                if (podeAndarDireita)
                    corpo.move(repulsao);
                else
                    hydra->setAtacou(false);
            }
            

        }

    }
    
}


