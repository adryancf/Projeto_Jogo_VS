#include "Espinho.h"

Espinho::Espinho(): clock_espinho(), countdown(0.0f)
{
	id = ID::espinho;
}

Espinho::Espinho(const sf::Vector2f tam, const sf::Vector2f pos): clock_espinho(), countdown(0.0f)
{
	corpo.setPosition(pos);
	corpo.setSize(tam);
	
	//corpo.setFillColor(sf::Color::White);
	texture.loadFromFile("assets/Cactus.png");
	corpo.setTexture(&texture);

	setDano(0.5f);
	id = ID::espinho;
}

Espinho::~Espinho()
{
}

void Espinho::Executar()
{
	movGravidade();
}

void Espinho::atacar(Entidade* adversario, float dano)
{
	if (adversario->getId() == ID::jogador) {
		Personagens* adv = static_cast<Personagens*>(adversario);
		adv->perdeVida(dano);
	}
}

void Espinho::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	countdown = clock_espinho.getElapsedTime().asSeconds();

	if (entidade->getId() == ID::plataforma)
		corrigeColisoes(entidade, inter_colisao);

	else if (entidade->getId() == ID::jogador)
	{
		Vector2f velocidade_entidade = entidade->getVelocidade();

		if (velocidade_entidade.x == VELOCIDADE_JOGADOR_X)
			velocidade_jogador = velocidade_entidade;

		//deixe o jogador lento se tiver em cima dele
		if (entidade->getEmCima()) {
			entidade->setVelocidade(Vector2f((velocidade_jogador.x / 4.f), velocidade_entidade.y));
			cout << velocidade_jogador.x / 2.f << endl;
			//tira a vida dele a cada 2s
			if (countdown >= 1.f) {
				atacar(entidade, dano);
				clock_espinho.restart();
			}
		}
				
	}
}
