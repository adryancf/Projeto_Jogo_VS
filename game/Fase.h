#pragma once

#include "Hydra.h"
#include "Jogador.h"
#include "Dragao.h"
#include "Plataforma.h"
#include "ListaEntidades.h"

#include "Ente.h"

#define ESPESSURA_PLATAFORMA 35.f
#define BORDA_ESQ 0.f
#define BORDA_DIR 1280.f
#define ALTURA_HYDRA 60.f
#define ALTURA_DRAGAO 70.f


class Fase: virtual public Ente
{
protected:
	Jogador* j1;

	virtual void criar_entidades() = 0;

public:
	Fase(Jogador *j);
	~Fase();

	virtual void Executar() = 0;
	virtual void criarPlataforma() = 0;
};

