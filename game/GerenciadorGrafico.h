#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>



/* PADRAO DE PROJETO SINGLETON */
//Esse padr?o de projeto consiste em garantir que a classe GerenciadorGrafico s? tenha uma inst?ncia
//Uma construtora privada -> NENHUMA OUTRA CLASSE CONSEGUE INSTANCIAR ESSA CLASSE
//um m?todo publico de acesso -> GARANTO UM ?NICO PONTO GLOBAL DE ACESSO DA CLASSE (LOGICA QUE GARANTE O SINGLETON: IF atributo == NULL -> new atributo)
//um atributo estatico da pr?pria classe

class GerenciadorGrafico
{
private:
	
	//Janela do jogo (criada nessa classe)
	sf::RenderWindow* window;

	//Tempo
	sf::Clock clock;
	

	/* Singlton */
	static GerenciadorGrafico* pGrafico;
	GerenciadorGrafico();

public:
	static float dt;

	~GerenciadorGrafico();
	static GerenciadorGrafico* getGerenciadorGrafico();
	sf::RenderWindow* getWindow();
	void limpar();
	void desenhar(sf::RectangleShape corpo);
	void mostrar();
	void fecharJanela();
	const bool isWindowOpen();

	void atualizaTempo();




};

