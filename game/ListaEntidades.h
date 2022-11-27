#pragma once

#include "Entidade.h"
#include "Lista.h"


class ListaEntidades
{

private:
	Lista<Entidade> listEnt;


public:
	ListaEntidades();
	~ListaEntidades();

	void renderElementos();
	bool verificaEntidadesVisiveis();
	int contaEntidadesMortas();

	Entidade* getJogador();
	const int getTamanhoLista();

	void incluir(Entidade* pE);

	void remover(Entidade* pE);
	void removerTudo();
	void removerTudoExcetoJogador(); //pensar num nome melhor

	const Lista<Entidade>* getList();

	Entidade* operator[](int x);


};

