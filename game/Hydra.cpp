#include "Hydra.h"

Hydra::Hydra(Jogador* p): Inimigo(), posHydra(Vector2f(0.0f, 0.0f))
{
	player = p;
	id = ID::hydra;

	inicializa();
}

Hydra::~Hydra()
{
	player = nullptr;
}

void Hydra::inicializa()
{
	//Forma Hydra
	corpo.setSize(Vector2f(HYDRA_X, HYDRA_Y));
	corpo.setFillColor(Color::Blue);

	//Atributos Hydra
	setVelocidade(Vector2f(0.3f, 0.f));
	setQuantidadeVida(4.0);
	setDano(1.0);

	repulsao = Vector2f(15.f, 0.f);

	raio_deteccao.x = 300.f;
	raio_deteccao.y = 300.f;
}

void Hydra::Mover()
{
	movGravidade();

	//Verifica se com a repulsao causada pela colisao entre os dois, o jogador pode andar ainda
	podePerseguir(player);

	if (atacou == true && podeAndar == true)
	{
		Vector2f posJogador = player->getCorpo().getPosition();
		posHydra = corpo.getPosition();

		if ((fabs(posJogador.x - posHydra.x) <= raio_deteccao.x)
			&& (fabs(posJogador.y - posHydra.y) <= raio_deteccao.y)) {

			PersegueJogador(posJogador, posHydra);
		}
	}

}


void Hydra::Executar()
{
	verificaVida();
	Mover();
}

void Hydra::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	ID id_entidade = entidade->getId();

	//Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
	if (id_entidade == ID::jogador) {
		atacou = true;
	
		//Ataque (S? ataca quando o jogador nao tiver em cima)
		Personagens* jogador = static_cast<Personagens*>(entidade);
		if(jogador->getEmCima() == false)
			atacar(jogador, dano);
	}

	else
		corrigeColisoes(entidade, inter_colisao);



}


