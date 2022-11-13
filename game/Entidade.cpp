#include "Entidade.h"

#define GRAVIDADE 9.98

Entidade::Entidade(): corpo(Vector2f(70.f, 70.f)), Ente(),
    colisao(false), 
    gravidade(true), 
    noChao(false), 
    isMoving(false),
    speed(Vector2f(0.0f, 0.0f))
{
    //Posicao padrao de todas as entidades
    corpo.setPosition(Vector2f(200.f, 500.f));
    ID = 0;
}


Entidade::~Entidade(){}

void Entidade::setVelocidade(Vector2f velocidade)
{
    speed = velocidade;
}

Vector2f* Entidade::getVelocidade()
{
    return &speed;
}

RectangleShape Entidade::getCorpo(){ return corpo; }

void Entidade::setColor(sf::Color cor)
{
    corpo.setFillColor(cor);
}

const int Entidade::getId()
{
    return ID;
}

void Entidade::setColisao(bool a)
{
    colisao = a;
}

void Entidade::movGravidade()
{
    if (colisao == false)
        gravidade = true;

    if (gravidade) {

        //Equa��o hor�ria da posi��o
        //speed.y = (speed.y * GerenciadorGrafico::dt) + ((GRAVIDADE * GerenciadorGrafico::dt)/2);
        
        //Manipula��o da integra��o de Euler = (Velocidade + posicao atual) + acelaracao
        //Velocidade + posicao atual = corpo.move -> ele soma a posicao atual mais o valor da velocidade

        float acelaracao = GRAVIDADE * GerenciadorGrafico::dt;
        speed.y += acelaracao;
        
        corpo.move(Vector2f(0.0f, speed.y));

    }
}


void Entidade::corrigeColisoes(Entidade* a, Vector2f inter)
{
    // Codigo baseado na video aula do monitor Matheus Burda:
    // https://www.youtube.com/watch?v=mxZMK7ZqFtE&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=9

    Vector2f aPos = a->getCorpo().getPosition();
    if (inter.x > inter.y) { // colisao em x
        if (corpo.getPosition().x < aPos.x)
        {
            corpo.move(Vector2f(inter.x, 0.0f));
        }

        else
        {
            corpo.move(Vector2f(-inter.x, 0.0f));
        }

        speed.x = 0.0f;

    }

    else // colisao em y
    {
        if(corpo.getPosition().y < aPos.y)
            corpo.move(Vector2f(0.f, inter.y));
        
        else
            corpo.move(Vector2f(0.f, -inter.y));

        //cout << corpo.getPosition().y << endl;
        speed.y = 0.0f;
    }


}

void Entidade::verificaColisaoPlataforma(Entidade* e)
{
    //Plataforma
    if (e->getId() == 3)
    {
        gravidade = false;
        noChao = true;

        //Zera a velocidade
        speed.y = 0.0f;
    }
}

void Entidade::setPosEntidade(Vector2f pos)
{
    corpo.setPosition(pos);
}

void Entidade::movimentaEntidade(Vector2f mov)
{
    corpo.move(mov);
}


