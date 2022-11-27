#pragma once

#include "GerenciadorGrafico.h"
#include "Jogador.h"


/*  GERENCIA TODOS OS EVENTOS DO JOGO  */
/*									   */
/*     PADRAO DE PROJETO SINGLETON     */


class GerenciadorEvento
{
private:
	GerenciadorGrafico* pGrafico;
	Jogador* Jogador1;
	Jogador* Jogador2;

	int tecla_pres;
	
	static GerenciadorEvento* pEvento;
	GerenciadorEvento();


public:
	~GerenciadorEvento();

	static GerenciadorEvento* getGerenciadorEvento();
	void setJogador1(Jogador* j);
	void setJogador2(Jogador* j);
	void verificaTeclaPressionada();
	void verificaTeclaPressionada(sf::Keyboard::Key tecla);
	void verificaTeclaSolta(sf::Keyboard::Key tecla);
	void Executar();
};

