#include "Ente.h"

Ente::Ente(): pGrafico(pGrafico->getGerenciadorGrafico())
{
	pGrafico->getWindow()->setVerticalSyncEnabled(true);
	visivel = true;
	id = ID::vazio;
}

Ente::Ente(GerenciadorGrafico* pG)
{
	visivel = true;
	pGrafico = pG;
	id = ID::vazio;
}

Ente::~Ente()
{ 
}

//Define o ID
void Ente::setId(ID Id)
{
	id = Id;
}

//Retorna o ID
const ID Ente::getId() const
{
	return id;
}

//Def se estah visivel ou nao
void Ente::setVisivel(bool visivel)
{
	this->visivel = visivel;
}

//Retorna o valor do atributo isShowing
const bool Ente::getVisivel() const
{
	return visivel;
}
