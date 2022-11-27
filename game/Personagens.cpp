#include "Personagens.h"

Personagens::Personagens(const float vida):
    Entidade(),
    podeAndarDireita(true),
    podeAndarEsquerda(true),
    olhandoDireita(false),
    olhandoEsquerda(false),
    podePular(false),
    vivo(true),
    atacou(false),
    podeAndar(true),
    direcaoMovimento("Nenhuma"),
    andando(false)
{
    this->q_vida = vida;
}

Personagens::~Personagens()
{
}


void Personagens::atacar(Entidade* adversario ,float dano)
{
    Personagens* adv = static_cast<Personagens*>(adversario);
    adv->perdeVida(dano);
}

void Personagens::setAtacou(bool ataque)
{
    atacou = ataque;

}

bool Personagens::getAtacou()
{
    return atacou;
}


// VIDA DO PERSONAGEM

void Personagens::setQuantidadeVida(float q)
{
    q_vida = q;
}

const float Personagens::getQuantidadeVida()
{
    return q_vida;
}

const bool Personagens::getVida() const
{
    return vivo;
}

void Personagens::verificaVida()
{
    if (q_vida <= 0 || verificarPosInvalidaEmY()) {
        
        vivo = false;
        visivel = false;

        //Tira ele do campo de visao para evitar colisoes indesejaveis
        setPosEntidade(Vector2f(-2000.f, -2000.f));
        gravidade = false;
    }
}

void Personagens::perdeVida()
{
    //DA PARA SUBSTITUIR POR UMA SOBRECARGA DE OPERADOR --
    if (vivo)
        q_vida--;
}

void Personagens::perdeVida(float dano)
{
    if (vivo)
        q_vida -= dano;
}

//MOVIMENTO E PULO


void Personagens::verificaPodeAndar(Vector2f pos)
{
    //Verifica se o personagem pode andar no movimento que ele pretende fazer (FUTURO)

    Vector2f pos_personagem = corpo.getPosition();

    if (pos_personagem.x + pos.x <= 0.0f) {
        podeAndarEsquerda = false;
        podeAndarDireita = true;
    }
    else if (pos_personagem.x + pos.x >= (RESOLUCAO_X - getSizeCorpo().x)) {
        podeAndarDireita = false;
        podeAndarEsquerda = true;
    }

    else {
        podeAndarDireita = true;
        podeAndarEsquerda = true;
    }
}

void Personagens::movimentaEntidade(Vector2f mov, bool direcao)
{
    verificaPodeAndar(mov);

    //DIREITA
    if (direcao && podeAndarDireita) {
        corpo.move(mov);
        olhandoDireita = true;
        olhandoEsquerda = false;
    }

    //ESQUERDA
    else if (!direcao && podeAndarEsquerda) {
        corpo.move(mov);
        olhandoDireita = false;
        olhandoEsquerda = true;
    }
}

const Vector2<bool> Personagens::getPodeAndar()
{
    Vector2<bool> vetor_resposta;

    if (podeAndarDireita)
        vetor_resposta.x = true;
    else
        vetor_resposta.x = false;

    if (podeAndarEsquerda)
        vetor_resposta.y = true;
    else
        vetor_resposta.y = false;

    return vetor_resposta;
}

const bool Personagens::getPodeAndarDireita()
{
    if (podeAndarDireita)
        return true;
    else
        return false;
}

const bool Personagens::getPodeAndarEsquerda()
{
    if (podeAndarEsquerda)
        return true;
    else
        return false;
}

const bool Personagens::getOlhar()
{

    if (olhandoDireita)
        return true;
    else if (olhandoEsquerda)
        return false;
}



void Personagens::setDirecaoMovimento(string direcao)
{
    direcaoMovimento = direcao;
}



void Personagens::pular(double tam_pulo)
{
    if (noChao || emCimaEntidade) {
        podePular = true;
    } else {
        podePular = false;
    }

    if (podePular)
    {
        //a alura do pulo vai ser determinada pela equação de torricelli
        speed.y = -sqrt(2.0 * GRAVIDADE * tam_pulo);
        noChao = false;
        emCimaEntidade = false;
    }

}

void Personagens::setAndando(bool estado_do_jogador)
{
    andando = estado_do_jogador;
}

const bool Personagens::getEstadoMovimentoJogador()
{
    return andando;
}






