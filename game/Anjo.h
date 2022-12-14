#pragma once

#include "Inimigo.h"
#include "Projetil.h"

class Anjo: public Inimigo
{
private:
	//Crio o projetil na fase, pois precico inclui-lo na lista de personagens
	Projetil* projetil;

	Personagens* alvo;
	Vector2f posAlvo;

	float tempo_atk;

	//Controle
	bool estaNoRaio;
	string direcao_alvo;

public:
	Anjo(Jogador* p, Projetil* b);
	~Anjo();

	void setAlvo(Personagens* alvo);
	const Personagens* getAlvo() const;
	void EncontraPosAlvo();


	const Projetil* getProjetil();
	virtual void atacar();

	void inicializa();

	virtual void Mover();
	virtual void Executar();
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);


};

