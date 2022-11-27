#pragma once
#include "Ente.h"
#include <iostream>
//#include "Jogo.h"

//Inicialmente nao vou derivar do ENTE e apenas seguir o TUTORIAL
class Menu : public Ente
{
private:
	//Como eh derivado do ENTE jah tem o posicao
	int pos;
	bool pressed, theselect;
	

	//Conhece a JANELA
	sf::RenderWindow* window;
	//sf::RectangleShape* winclose;

	//A fonte
	sf::Font* font;
	//A textura
	sf::Texture* image;
	//A sprite
	sf::Sprite* bg;
	//Guarda as coordenadas do mouse
	sf::Vector2i pos_mouse;
	sf::Vector2i mouse_coord;

	//As opções em tela
	std::vector<const char*> options; //Os nomes no menu
	std::vector<sf::Vector2f> coords;
	//Utilizada para renderizar os textos
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;

protected:
	void set_values();
	void loop_events();
	void draw_all();
public:
	Menu();
	~Menu();
	void run_menu();

	//redefinindo a executar
	void Executar();
};

