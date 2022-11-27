#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(ListaEntidades* l_personagem, ListaEntidades* l_obstaculos):
	lista_obstaculos(l_obstaculos),
	lista_personagens(l_personagem)

{}

GerenciadorColisoes::~GerenciadorColisoes()
{
	lista_personagens = nullptr;
	lista_obstaculos = nullptr;
}

sf::Vector2f GerenciadorColisoes::calculaColisoes(Entidade* e1, Entidade* e2)
{
	sf::Vector2f colisao;

	sf::Vector2f pos1 = e1->getCorpo().getPosition();
	sf::Vector2f pos2 = e2->getCorpo().getPosition();

	sf::Vector2f tam1 = e1->getCorpo().getSize();
	sf::Vector2f tam2 = e2->getCorpo().getSize();

	//Modulo da distancia entre os centros dos elementos menos a soma da metade do tamanho
	
	colisao.x = fabs((pos1.x + (tam1.x/2.0f)) - (pos2.x + (tam2.x/2.0f))) - 
				((tam1.x / 2.0f) + (tam2.x / 2.0f));

	colisao.y = fabs((pos1.y + (tam1.y / 2.0f)) - (pos2.y + (tam2.y / 2.0f))) -
		((tam1.y / 2.0f) + (tam2.y / 2.0f));

	return colisao;
}

void GerenciadorColisoes::verificaColisoes()
{

	colisaoPersonagens();
	colisaoPersonagemObstaculos();
	colisaoObstaculos();
	
}

void GerenciadorColisoes::colisaoPersonagens()
{
	//COLISAO ENTRE PERSONAGEM E JOGADOR (FAZER ISSO)
	Entidade* Jogador = nullptr;
	
	Entidade* aux = nullptr;
	Vector2f Colisao;

	
	for (int i = 0; i < 2; i++) {
		Jogador = lista_personagens->operator[](i);

		//Verifica se houve colis�o (NAO TEM PROBLEMA SE OS JOGADORES SE COLIDIREM)
		for (int j = i+1; j < lista_personagens->getTamanhoLista(); j++) {

			aux = lista_personagens->operator[](j);

			Colisao = calculaColisoes(Jogador, aux);
			if (Colisao.x < 0.0f && Colisao.y < 0.0f) {
				Jogador->Colisao(aux, Colisao);
				aux->Colisao(Jogador, Colisao);
			}
		}
	}

}

void GerenciadorColisoes::colisaoPersonagemObstaculos()
{
	Entidade* aux1 = nullptr;
	Entidade* aux2 = nullptr;
	Vector2f Colisao;

	//O pair transforma dois tipos em um so
	vector <pair<Entidade*, Entidade*>> vector_colisoes;
	vector <Vector2f> valor_colisao;

	//Verifico a colis�o entre os personagens e os obstaculos
	for (unsigned int i = 0; i < lista_personagens->getTamanhoLista(); i++)
	{
		aux1 = lista_personagens->operator[](i);

		for (int j = 0; j < lista_obstaculos->getTamanhoLista(); j++) {
			aux2 = lista_obstaculos->operator[](j);

			Colisao = calculaColisoes(aux1, aux2);

			if (Colisao.x < 0.0f && Colisao.y < 0.0f)
			{
				vector_colisoes.push_back(make_pair(aux1, aux2));
				valor_colisao.push_back(Colisao);

			}

			aux1->setColisaoPlataforma(false);

		}
	}

	for (unsigned int i = 0; i < vector_colisoes.size(); i++) {

		if(vector_colisoes[i].second->getId() == ID::plataforma)
			vector_colisoes[i].first->setColisaoPlataforma(true);

		vector_colisoes[i].first->Colisao(vector_colisoes[i].second, valor_colisao[i]);
		vector_colisoes[i].second->Colisao(vector_colisoes[i].first, valor_colisao[i]);

	}


}

void GerenciadorColisoes::colisaoObstaculos()
{
	Entidade* aux1 = nullptr;
	Entidade* aux2 = nullptr;
	Vector2f Colisao;
	for (unsigned int i = 0; i < lista_obstaculos->getTamanhoLista(); i++) {

		aux1 = lista_obstaculos->operator[](i);

		//Verifica se houve colis�o
		for (int j = i+1; j < lista_obstaculos->getTamanhoLista(); j++) {

			aux2 = lista_obstaculos->operator[](j);

			Colisao = calculaColisoes(aux1, aux2);

			if (Colisao.x < 0.0f && Colisao.y < 0.0f) {
				aux1->Colisao(aux2, Colisao);
				aux2->Colisao(aux1, Colisao);
			}
		}
	}
}

void GerenciadorColisoes::setListas(ListaEntidades* l_personagem, ListaEntidades* l_obstaculos)
{
	lista_personagens = l_personagem;
	lista_obstaculos = l_obstaculos;
}

void GerenciadorColisoes::Executar()
{
	verificaColisoes();
}
