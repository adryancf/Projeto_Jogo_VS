#include "Fase.h"

Fase::Fase(Jogador *j)
{
	j1 = j;

	/* CRIA A LISTA DE ENTIDADES DA FASE */
	lista_personagem = new ListaEntidades;
	lista_personagem->listEnt.push(j1);
	
	lista_obstaculos = new ListaEntidades;
	//INICIALIZA as entidades da fase
	criar_entidades();
}

Fase::~Fase()
{
	//Chama a destrutora da lista?
	delete lista_personagem;
	delete lista_obstaculos;
}

void Fase::Executar()
{
}

void Fase::criar_entidades()
{

	Plataforma* p1 = new Plataforma(Vector2f(500.f, 40.f), Vector2f(0.f, 620.f));
	
	lista_obstaculos->listEnt.push(p1);

	
	//lista_obstaculos->listEnt.push(p2);

	//Implementação de mais de um inimigo (terminar depois)

	/*/
	//Cria de 3 a 10 inimigos
	int num_inimigos = 3 + rand() % 10;

	for (int i = 0; i < num_inimigos; i++) {
		aux = new Inimigo;
		aux->setWindow(window);
		lista_entidades->listEnt.push(aux);
		delete aux;
	}
	/*/

	i1 = new Inimigo(j1);
	lista_personagem->listEnt.push(i1);

}

ListaEntidades* Fase::getListaPersonagem()
{
	return lista_personagem;
	
}

ListaEntidades* Fase::getListaObstaculo()
{
	return lista_obstaculos;
}
