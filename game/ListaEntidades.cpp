#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():listEnt()
{
}

ListaEntidades::~ListaEntidades()
{
	listEnt.limpar();
}

void ListaEntidades::renderElementos()
{

	for (int j = 0; j < getTamanhoLista(); j++)
	{
		Entidade* aux = listEnt[j];
		
		if (aux && aux->getVisivel()) {
			aux->Executar();
			aux->render();
		}

	}


}

bool ListaEntidades::verificaEntidadesVisiveis()
{
	//Percorrer a lista e contar quantas entidades estao com a flag visivel como false
	for (int i = 0; i < getTamanhoLista(); i++){
	
		if (listEnt[i]->getId() == ID::anjo || listEnt[i]->getId() == ID::fantasma || listEnt[i]->getId() == ID::hydra) {
			if (listEnt[i]->getVisivel() == true)
				return true;
		}
	}

	return false;


}

int ListaEntidades::contaEntidadesMortas()
{
	int entidades = 0;
	//Percorrer a lista e contar quantas entidades estao com a flag visivel como false
	for (int i = 0; i < getTamanhoLista(); i++) {

		if (listEnt[i]->getId() == ID::anjo || listEnt[i]->getId() == ID::fantasma || listEnt[i]->getId() == ID::hydra) {
			if (listEnt[i]->getVisivel() == false)
				entidades++;
		}
	}

	return entidades;
}

Entidade* ListaEntidades::getJogador()
{
	for (int i = 0; i < getTamanhoLista(); i++)
	{
		if (listEnt[i]->getId() == ID::jogador)
		{
			return listEnt[i];
		}
	}
}

const int ListaEntidades::getTamanhoLista()
{
	return listEnt.getTamanho();
}

void ListaEntidades::incluir(Entidade* pE)
{
	if (pE == nullptr)
	{
		cout << "Ponteiro pE � o nullptr. Checar ListaEntidades::push" << endl;
		exit(1);
	}

	listEnt.push(pE);
}

void ListaEntidades::remover(Entidade* pE)
{
	if (pE == nullptr)
	{
		std::cout << "Impos�vel remover nullptr. Checar ListaEntidades::pop." << std::endl;
		exit(1);
	}
	listEnt.pop(pE);
}

void ListaEntidades::removerTudo()
{
	listEnt.limpar();
}

void ListaEntidades::removerTudoExcetoJogador()
{
	for (int i = 0; i < listEnt.getTamanho(); i++)
	{
		if (listEnt[i]->getId() != ID::jogador)
		{
			listEnt.pop(listEnt[i]);
		}
	}
}

const Lista<Entidade>* ListaEntidades::getList()
{
	return &listEnt;
}

Entidade* ListaEntidades::operator[](int x)
{
	return listEnt[x];
}
