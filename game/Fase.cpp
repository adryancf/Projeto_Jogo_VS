#include "Fase.h"

Fase::Fase(Jogador *j1, Jogador* j2): fundo(Vector2f(RESOLUCAO_X, RESOLUCAO_Y)),
	numero_instancias(0), 
	j1(j1), 
	j2(j2),
	plataforma_fase(nullptr), 
	caixa(nullptr), 
	ativa(true), 
	hydra(nullptr),
	pColisoes(nullptr),
	lista_obstaculos(nullptr),
	lista_personagem(nullptr),
	tempo_fase(0.f)
{}

Fase::~Fase()
{
	//Aterrando ponteiros
	lista_obstaculos = nullptr;
	lista_personagem = nullptr;
	j1 = nullptr;
	j2 = nullptr;
}

const float Fase::tempoFase()
{
	return (relogio_fase.getElapsedTime().asSeconds());
}

void Fase::setFundo(string path_fundo)
{
	img_fundo.loadFromFile(path_fundo);
	fundo.setTexture(&img_fundo);
}

void Fase::setFundo(string path_fundo, IntRect rect)
{
	img_fundo.loadFromFile("assets/Idle.png", rect);
	fundo.setTexture(&img_fundo);
}

int Fase::gerarNumeroAleatorio(int min, int max)
{
	return (min + (std::rand() % (max - min + 1)));;
}

int Fase::gerarNumeroAleatorio(float min, float max)
{

	int max_int = static_cast<int>(max);
	int min_int = static_cast<int>(min);

	int numero = min_int + (std::rand() % (max_int - min_int + 1));

	return (numero);
}

void Fase::verificaTerminoFase()
{
	ativa = lista_personagem->verificaEntidadesVisiveis();
}

const bool Fase::getAtiva()
{
	return ativa;
}

void Fase::criarLista()
{
	/* CRIA A LISTA DE ENTIDADES DA FASE */
	lista_personagem = new ListaEntidades;
	lista_obstaculos = new ListaEntidades;

	if (j1 != nullptr) {
		lista_personagem->incluir(j1);
		cout << "INCLUI J1 NA LISTA" << endl;
	}
	if (j2 != nullptr) {
		lista_personagem->incluir(j2);
		cout << "INCLUI J2 NA LISTA" << endl;
	}
	//Gerenciador
	pColisoes = new GerenciadorColisoes(lista_personagem, lista_obstaculos);

}

void Fase::deletaListas()
{
	if (pColisoes != nullptr)
		delete pColisoes;

	else
		cout << "Nao eh possivel deletar ponteiro null (pColisoes - Fase.cpp)" << endl;
	
	if (lista_personagem) {
		lista_personagem->removerTudo();
		delete lista_personagem;

		lista_personagem = nullptr;
	}

	else
		cout << "Nao eh possivel deletar ponteiro null (lista_personagens - Fase.cpp)" << endl;

	if (lista_obstaculos) {
		lista_obstaculos->removerTudo();
		delete lista_obstaculos;

		lista_obstaculos = nullptr;
	
	}

	else
		cout << "Nao eh possivel deletar ponteiro null (lista_obstaculos - Fase.cpp)" << endl;
	
}

ListaEntidades* Fase::getListaPersonagem()
{
	if (lista_personagem)
		return lista_personagem;
	else
		return nullptr;
}

ListaEntidades* Fase::getListaObstaculo()
{
	if (lista_obstaculos)
		return lista_obstaculos;
	else
		return nullptr;
}




