#pragma once

#include "Personagens.h"

//Adicionar SPRITE NO PROJETIL

class Projetil: public Entidade
{
private:

	Personagens* portador;

	sf::Clock t;
	float tempo_ataque;

	bool repouso;

public:
	Projetil();
	~Projetil();

	//ESTADO INICIAL
	void verificarBordas();
	void estadoInicial();
	void atualizaPosicaoInicial();
	const bool getRepouso();

	//PORTADOR
	void setPortador(Personagens* portador);
	const Personagens* getPortador() const;

	//ATAQUE
	virtual void atacar(Entidade* adversario, float dano);
	void atirar(string direcao, float tempo);

	//LOOP E COLISAO
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

