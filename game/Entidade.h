#pragma once
#include "Ente.h"

//Fazer uma classe ID
enum ID
{
	eempty = 0,
	jogador,
	hydra,
	anjo,
	dragao,
	caixa,
	espinho,
	plataforma,
	inimigo,
	obstaculo,
	projetil
};


//derivando como virtual public
class Entidade : virtual public Ente
{
protected:
	//Toda entidade tem um shape
	RectangleShape corpo;
 
	//Toda entidade sofre uma velocida (gravidade e movimento)
	sf::Vector2f speed;

	//Nao sei se seria util esse atributo (pois a posicao do corpo pode ser obtida atraves de um getPosicao())
	Vector2f posicao;

	//Util para colisoes entre entidades
	sf::Vector2f repulsao;

	//Entidades sao capazes de causar dano
	float dano;

	ID id;

	//Variaveis de controle
	bool visivel;
	bool colisaoPlataforma;
	bool gravidade;
	bool noChao;
	bool emCima;

public:

	Entidade(ID idd = eempty);
	~Entidade();

	//Controle
	void render();

	//Funcao para verificar se a entidade esta dentro da area permitida na tela
	const bool verificarPosInvalida();


	//ATRIBUTOS
	void setVelocidade(Vector2f velocidade);
	Vector2f getVelocidade();
	const Vector2f getRepulsao();
	void setDano(float dano);
	const float getDano() const;
	const bool getVisivel() const;

	//Entidades sao capazes de causar dano em outras entidades
	virtual void atacar(Entidade* adversario, float dano) = 0;


	//CORPO
	const RectangleShape getCorpo() const;
	const Vector2f getSizeCorpo() const;
	void setColor(sf::Color cor);
	void setPosEntidade(Vector2f pos);
	const Vector2f getPosicao() const;
	

	//retorna o ID
	ID getId() const;

	//COLISAO E GRAVIDADE
	void setColisaoPlataforma(bool estaNaPlataforma);
	void setChao(bool estaNoChao);
	const bool getEmCima();
	void movGravidade();

	void corrigeColisoes(Entidade* a, Vector2f inter);
	
	virtual void Executar() = 0;
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

};

