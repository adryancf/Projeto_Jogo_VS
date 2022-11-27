#include "Fantasma.h"

Fantasma::Fantasma(): Inimigo(), tempo_de_ataque(1.0)
{
    id = ID::fantasma;
    inicializaVariaveis();
}

Fantasma::~Fantasma()
{
}

void Fantasma::inicializaVariaveis()
{
    //Forma Fantasma
    corpo.setSize(Vector2f(FANTASMA_X, FANTASMA_Y));
    //setColor(Color::Red);

    //Atributos Fantasma
    setVelocidade(Vector2f(0.6f, 0.f));
    setQuantidadeVida(3.0);
    setDano(0.5);

    repulsao_direita = Vector2f(30.f, 0.f);
    repulsao_esquerda = Vector2f(-30.f, 0.f);


    sf::IntRect rect(1, 4, 30, 27);
    texture.loadFromFile("assets/ghost-Sheet.png", rect);
    corpo.setTexture(&texture);
}

const float Fantasma::getTempoAtaque() const
{
    return tempo_de_ataque;
}


void Fantasma::Mover()
{
    //Aplica a gravidade
    movGravidade();
    movAleatorio();

    direcaoMovimento = string("nulo");

}

void Fantasma::Executar()
{
    verificaVida();
    //cout << " Vida Dragao: " << q_vida << endl;

    Mover();
}

void Fantasma::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
    ID id_entidade = entidade->getId();

    //Nao corrige colisao com o jogador, pois la ele ja chama essa funcao
    if (id_entidade == ID::jogador) {

        Personagens* jogador = static_cast<Personagens*>(entidade);

        if (!jogador->getEmCima()) {
            //Se o jogador estiver em movimento
            if (jogador->getEstadoMovimentoJogador() == true) {

                if (jogador->getOlhar()) {
                    movimentaEntidade(repulsao_direita, true);
                    jogador->movimentaEntidade(repulsao_esquerda, false);
                }
                else if (!jogador->getOlhar()) {
                    movimentaEntidade(repulsao_esquerda, false);
                    jogador->movimentaEntidade(repulsao_direita, true);
                }
            }
            else
            {
                if (olhandoDireita) {
                    movimentaEntidade(repulsao_esquerda, false);
                    jogador->movimentaEntidade(repulsao_direita, true);

                }
                else if (olhandoEsquerda) {
                    movimentaEntidade(repulsao_direita, true);
                    jogador->movimentaEntidade(repulsao_esquerda, false);

                }


            }

            //ATAQUE
            atacar(jogador, dano);

            jogador->atacar(this, jogador->getDano());
        }

    }

    else
        corrigeColisoes(entidade, inter_colisao);

}
