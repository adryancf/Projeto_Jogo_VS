#pragma once

#include "Inimigo.h"

class Hydra: public Inimigo
{
private:
	Vector2f posHydra;

public:
	Hydra(Jogador* p);
	~Hydra();

	void inicializa();

	virtual void Mover();
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

//Como funciona a Hydra
/*
	Ela persegue o Jogador quando ? atacada
	Fica parada ate o jogador a atingir

	O seu ataque nao move o jogador

*/
