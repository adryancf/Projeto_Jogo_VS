#pragma once

#include "Obstaculo.h"
#include "Personagens.h"
#include "stdafx.h"

class Espinho : public Obstaculo
{
private:

	sf::Clock clock_espinho;
	float countdown;

	Vector2f velocidade_jogador;

public:
	Espinho();
	Espinho(const sf::Vector2f tam, const sf::Vector2f pos);
	~Espinho();

	virtual void Executar();
	virtual void atacar(Entidade* adversario, float dano);
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);
};

