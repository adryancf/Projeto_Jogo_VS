#include "Plataforma.h"

Plataforma::Plataforma(const Vector2f tam, const Vector2f pos)
{
	cor = sf::Color::Red;
	this->setVariaveis(tam, pos);

	id = ID::plataforma;
}

Plataforma::Plataforma()
{
	id = ID::plataforma;
}

Plataforma::~Plataforma()
{
}

void Plataforma::Executar()
{
	movGravidade();
	anulaGravidade();
}

//A plataforma jamais ataca
void Plataforma::atacar(Entidade* adversario, float dano)
{
}

void Plataforma::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	if (entidade->getId() == jogador)
		entidade->setVelocidade(Vector2f(VELOCIDADE_JOGADOR_X, entidade->getVelocidade().y));
}

//define as variaveis - corpo - textura
void Plataforma::setVariaveis(const Vector2f tam, const Vector2f pos)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	corpo.setFillColor(cor);
	texture.loadFromFile("assets/brownPlatform.png");
	corpo.setTexture(&texture);
}
