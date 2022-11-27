#pragma once
#include "Obstaculo.h"
class Plataforma : public Obstaculo
{

private:
    sf::Color cor;
public:
    Plataforma(const Vector2f tam, const Vector2f pos);
    Plataforma();
    ~Plataforma();

    virtual void Executar();
    virtual void atacar(Entidade* adversario, float dano);
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

    void setVariaveis(const Vector2f tam, const Vector2f pos);
};

