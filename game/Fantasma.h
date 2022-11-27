#pragma once

#include "Inimigo.h"

class Fantasma: public Inimigo
{

private:
	float tempo_de_ataque;

public:
	Fantasma();
	~Fantasma();

	const float getTempoAtaque() const;
	void inicializaVariaveis();

	virtual void Mover();
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);
};