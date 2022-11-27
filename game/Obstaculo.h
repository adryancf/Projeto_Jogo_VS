#pragma once
#include "Entidade.h"

class Obstaculo :
    public Entidade
{
protected:


public:
    Obstaculo();
    ~Obstaculo();

    void anulaGravidade();

    virtual void Executar() = 0;
    virtual void atacar(Entidade* adversario, float dano) = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;



};

