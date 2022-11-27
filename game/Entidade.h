#pragma once
#include "Ente.h"

//derivando como virtual public
class Entidade : virtual public Ente
{
protected:
	//Toda entidade tem um shape
	RectangleShape corpo;
 
	//Textura
	sf::Texture texture;

	//Toda entidade sofre uma velocida (gravidade e movimento)
	sf::Vector2f speed;

	Vector2f posicao;

	//Util para colisoes entre entidades
	sf::Vector2f repulsao_direita;
	sf::Vector2f repulsao_esquerda;

	//Entidades sao capazes de causar dano
	float dano;


	//Variaveis de controle
	
	bool colisaoPlataforma;
	bool gravidade;
	bool noChao;
	bool emCimaEntidade;

public:

	Entidade(ID idd = ID::vazio);
	~Entidade();

	//Controle
	void render();

	//Funcao para verificar se a entidade esta dentro da area permitida na tela
	const bool verificarPosInvalida();
	const bool verificarPosInvalidaEmY();



	//ATRIBUTOS
	void setVelocidade(Vector2f velocidade);
	const Vector2f getVelocidade() const;
	void setDano(float dano);
	const float getDano() const;

	//Entidades sao capazes de causar dano em outras entidades
	virtual void atacar(Entidade* adversario, float dano) = 0;


	//CORPO
	const RectangleShape getCorpo() const;
	const Vector2f getSizeCorpo() const;
	void setColor(sf::Color cor);
	void setPosEntidade(Vector2f pos);
	const Vector2f getPosicao() const;
	

	//COLISAO E GRAVIDADE
	void setColisaoPlataforma(bool estaNaPlataforma);
	void setChao(bool estaNoChao);
	const bool getEmCima();
	void movGravidade();

	void corrigeColisoes(Entidade* a, Vector2f inter);
	
	virtual void Executar() = 0;
	virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

	void setTextura(std::string str);

};

