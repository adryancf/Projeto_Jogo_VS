#pragma once

#include "stdafx.h"
#include "GerenciadorGrafico.h"

/* Derivadas = Jogo, Entidade, Fase */

class Ente
{
protected:
	//Todo ENTE deve conhecer a parte Gr?fica do jogo (Janela - SFML)
	GerenciadorGrafico* pGrafico;


public:
	Ente();
	Ente(GerenciadorGrafico* pG);
	~Ente();

	void setWindow(GerenciadorGrafico* pG);
	GerenciadorGrafico* getGrafico();

	virtual void Executar() = 0;
	void Print(); //posso fazer um render


};

