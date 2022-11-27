#include "Caixa.h"

Caixa::Caixa() : ehFixa(true)
{
	id = ID::caixa;
}

Caixa::Caixa(const sf::Vector2f tam, const sf::Vector2f pos, bool estado_caixa):
	ehFixa(estado_caixa)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	//corpo.setFillColor(sf::Color::Red);
	sf::IntRect rect(199, 23, 34, 23);
	texture.loadFromFile("assets/wm.png", rect);
	corpo.setTexture(&texture);

	id = ID::caixa;
}

Caixa::~Caixa()
{
}

//define o estado da caixa: fixa ou nao : true ou false
void Caixa::setEstadoCaixa(bool estado_caixa)
{
	ehFixa = estado_caixa;
}

//retorna o estado da caixa: fixa ou nao : true ou false
const bool Caixa::getEstadoCaixa()
{
	return ehFixa;
}


void Caixa::Executar()
{
	movGravidade();
}

//a caixa nao ataca nada
void Caixa::atacar(Entidade* adversario, float dano)
{
}

//trata a colisao da caixa com o jogador
void Caixa::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	if (entidade->getId() == jogador && entidade->getVelocidade().x != VELOCIDADE_JOGADOR_X) {
		entidade->setVelocidade(Vector2f(VELOCIDADE_JOGADOR_X, entidade->getVelocidade().y));
	}


	if (ehFixa) {
		if (entidade->getId() == ID::plataforma || entidade->getId() == ID::caixa || entidade->getId() == ID::espinho)
			corrigeColisoes(entidade, inter_colisao);
	}
	else {
		if (verificarPosInvalida() || entidade->getId() == ID::caixa) {
			ehFixa = true;
			cout << "entrei" << endl;
		}
		else {
			if(entidade->getId() == ID::jogador || entidade->getId() == ID::plataforma)
				corrigeColisoes(entidade, inter_colisao);
		}
	}
}
