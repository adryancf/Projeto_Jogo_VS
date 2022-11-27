#pragma once

#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "Id.h"

class Ente
{
protected:
	//Todo ENTE deve conhecer a parte Gráfica do jogo (Janela - SFML)
	GerenciadorGrafico* pGrafico;

	//Todo ENTE tem um ID
	ID id;

	//Todo ENTE pode ou nao estar VISIVEL
	bool visivel;

public:
	Ente();
	Ente(GerenciadorGrafico* pG);
	~Ente();

	virtual void Executar() = 0;

	//ID
	void setId(ID Id);
	const ID getId() const;

	//VISIBILIDADE
	void setVisivel(bool visivel);
	const bool getVisivel() const;
};

