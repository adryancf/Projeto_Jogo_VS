
#include "Inimigo.h"


Inimigo::Inimigo():Personagens(), tempo_mov(), 
	player1(nullptr), 
	player2(nullptr), 
	jogadorEmCima(false),
	estaNoRaio(false),
	jogadoresAtivos("Dois")

{   
    movRandom = rand() % 4; //SEED FALTANTE
    id = ID::inimigo; // ARRUMAR ID
}


Inimigo::~Inimigo()
{
	player1 = nullptr;
	player2 = nullptr;
}

string Inimigo::verficaJogadoresAtivos(Jogador* j1, Jogador* j2)
{
	if (j1 && j2)
		return "Dois";

	else if (j1)
		return "Jogador1";

	else if (j2)
		return "Jogador2";

	else
		return "Nenhum";

}

void Inimigo::movAleatorio()
{
    /* O movimento aleatorio se da por um valor sorteado entre 1 e 4 a cada 0.5s */
    if (noChao || emCimaEntidade) {
        if (movRandom == 0) {
            movimentaEntidade(Vector2f(speed.x, 0.f), true);
        }
        else if (movRandom == 1) {
            movimentaEntidade(Vector2f(-speed.x, 0.f), false);
        }
    }
    
    float dt = tempo_mov.getElapsedTime().asSeconds();
    if (dt >= 1.0f) {
        movRandom = rand() % 2;
        tempo_mov.restart();
    }

}

void Inimigo::qualPerseguir(Vector2f pos_inimigo)
{
	if (jogadoresAtivos == "Dois")
		persegurDoisJogadores(player1->getPosicao(), player2->getPosicao(), pos_inimigo);

	else if (jogadoresAtivos == "Jogador1")
		perseguirUmJogador(player1, pos_inimigo);

	else if (jogadoresAtivos == "Jogador2")
		perseguirUmJogador(player2, pos_inimigo);

	else if (jogadoresAtivos == "Nenhum")
		cout << "Nenhum Jogador vivo | Hydra.cpp" << endl;
}

void Inimigo::perseguirUmJogador(Jogador* j, Vector2f posInimimgo)
{
	if (j) {
		podePerseguir(j);

		if (podeAndar == true)

		{
			estaNoRaio = verificaEntidadeNoRaio(j->getPosicao(), posInimimgo, raio_deteccao);

			if (estaNoRaio) {

				PersegueJogador(j->getPosicao(), posInimimgo);
			}
		}
	}
}

void Inimigo::persegurDoisJogadores(Vector2f pos_j1, Vector2f pos_j2, Vector2f pos_inimigo)
{
	Vector2f proximidadeJogador1;
	proximidadeJogador1.x = fabs(pos_j1.x - pos_inimigo.x);
	proximidadeJogador1.y = fabs(pos_j1.y - pos_inimigo.y);

	Vector2f proximidadeJogador2;
	proximidadeJogador2.x = fabs(pos_j2.x - pos_inimigo.x);
	proximidadeJogador2.y = fabs(pos_j2.y - pos_inimigo.y);

	if (proximidadeJogador1.x <= proximidadeJogador2.x || proximidadeJogador1.y <= proximidadeJogador2.y)
	{
		podePerseguir(player1);

		estaNoRaio = verificaEntidadeNoRaio(player1->getPosicao(), getPosicao(), raio_deteccao);

		if (estaNoRaio && podeAndar) {

			PersegueJogador(pos_j1, pos_inimigo);
		}
	}
	else
	{
		podePerseguir(player2);

		estaNoRaio = verificaEntidadeNoRaio(player2->getPosicao(), getPosicao(), raio_deteccao);

		if (estaNoRaio && podeAndar) {

			PersegueJogador(pos_j2, pos_inimigo);
		}
	}
}

Personagens* Inimigo::verificaMaisProximo(Jogador* j1, Jogador* j2, Vector2f pos_inimigo)
{

	Vector2f pos_j1 = j1->getPosicao();
	Vector2f pos_j2 = j2->getPosicao();

	Vector2f proximidadeJogador1;
	proximidadeJogador1.x = fabs(pos_j1.x - pos_inimigo.x);
	proximidadeJogador1.y = fabs(pos_j1.y - pos_inimigo.y);

	Vector2f proximidadeJogador2;
	proximidadeJogador2.x = fabs(pos_j2.x - pos_inimigo.x);
	proximidadeJogador2.y = fabs(pos_j2.y - pos_inimigo.y);

	if (proximidadeJogador1.x <= proximidadeJogador2.x || proximidadeJogador1.y <= proximidadeJogador2.y)
	{
		return j1;
	}
	else
		return j2;

}

bool Inimigo::verificaEntidadeNoRaio(Vector2f pos_entidade, Vector2f pos_inimigo, Vector2f raio)
{
	if ((fabs(pos_entidade.x - pos_inimigo.x) <= raio.x) && (fabs(pos_entidade.y - pos_inimigo.y) <= raio.y)) {
		return true;

	}
	else
		return false;
}

void Inimigo::PersegueJogador(Vector2f posJogador, Vector2f posInimimgo)
{

	//fun�ao altera as flags 
	Vector2f diferenca = posJogador - posInimimgo;

	if ((diferenca.x > 0)) {
		movimentaEntidade(Vector2f(speed.x, 0.0), true);
	}

	else if ((diferenca.x < 0))
	{
		movimentaEntidade(Vector2f(-speed.x, 0.0), false);
	}

	//PENSAR EM UMA FORMA PARA PERSEGUIR EM Y

	/*
	else if (diferenca.y > 0.0 || diferenca.y < 0.0)
	{
		cout << "ENTREI " << endl;
		if (podeAndarDireita == true) {
			movimentaEntidade(Vector2f(speed.x, 0.0), true);
		}
		else if (podeAndarEsquerda == true) {
			movimentaEntidade(Vector2f(-speed.x, 0.0), false);

		}
	}
	*/

}

void Inimigo::podePerseguir(Personagens* personagem)
{
	bool podeAndarPersonagem;

	if (olhandoDireita) {

		personagem->verificaPodeAndar(repulsao_direita);
		podeAndarPersonagem = personagem->getPodeAndarDireita();

		if (podeAndarPersonagem)
			podeAndar = true;
		else if (!podeAndarPersonagem)
			podeAndar = false;
	}
	else if (olhandoEsquerda) {
		
		personagem->verificaPodeAndar(repulsao_esquerda);
		podeAndarPersonagem = personagem->getPodeAndarEsquerda();

		if (podeAndarPersonagem)
			podeAndar = true;
		else if (!podeAndarPersonagem)
			podeAndar = false;
	}
}

