#pragma once
#include "Entidade.h"
#include "Obstaculo.h"
class Caixa : public Obstaculo
{
private:

	//Define a propriedade da Caixa: Fixa ou movel
	bool ehFixa;

public:
	Caixa();
	Caixa(const sf::Vector2f tam, const sf::Vector2f pos, bool estado_caixa);
	~Caixa();

	void setEstadoCaixa(bool estado_caixa);
	const bool getEstadoCaixa();

	virtual void Executar();
	virtual void atacar(Entidade* adversario, float dano);
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

};

