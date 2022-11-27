#pragma once
#include "Fase.h"

class Fase1: public Fase
{
private:

	//NESSA FASE VAI TER ESPECIFICAMENTE
	Fantasma* fantasma;

	virtual void criar_entidades();

public:
	Fase1(Jogador* j1, Jogador* j2);
	~Fase1();
	
	//Personagem
	void criarFantasma();
	virtual void criarHydra();
	virtual void criarPlataforma();
	virtual void criarCaixa();

	virtual void Executar();


};

