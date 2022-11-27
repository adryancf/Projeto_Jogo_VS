#include "Anjo.h"

Anjo::Anjo(Jogador* p1, Jogador* p2, Projetil* b): 
    Inimigo(), 
    projetil(b),
    tempo_atk(1.0f),
    posAlvo(Vector2f(0.f, 0.f))
{
    player1 = p1;
    player2 = p2;

    jogadoresAtivos = verficaJogadoresAtivos(p1, p2);
    cout << "Anjo: Jogadores ativos: " << jogadoresAtivos << endl;

    id = ID::anjo;

    projetil->setPortador(this);

    inicializaVariaveis();
    
    sf::IntRect rect(83, 29, 25, 35);
    texture.loadFromFile("assets/Run-Sheet.png", rect);
    corpo.setTexture(&texture);
}

Anjo::~Anjo()
{
    if (alvo)
        alvo = nullptr;

    if(projetil)
        projetil = nullptr;
}

//
void Anjo::inicializaVariaveis()
{
    //Forma Anjo
    corpo.setSize(Vector2f(ANJO_X, ANJO_Y));
    setColor(Color::Cyan);

    //Atributos Anjo
    setVelocidade(Vector2f(0.5f, 0.f));
    setQuantidadeVida(15.0);

    raio_deteccao = Vector2f(500.f, JOGADOR_Y);

    repulsao_direita = Vector2f(50.f, 0.f);
    repulsao_esquerda = Vector2f(-50.f, 0.f);

    //Dano Fisico
    //setDano(1.5f);
    if (projetil)
        projetil->setDano(0.0f);
}

//define que a variavel alvo recebe o parâmetro alvo (ptr)
void Anjo::setAlvo(Personagens* alvo)
{
    this->alvo = alvo;
}

//retorna um ponteiro para alvo
const Personagens* Anjo::getAlvo() const
{
    return alvo;
}

//retorna um ponteiro para projetil
const Projetil* Anjo::getProjetil()
{
    return projetil;
}


//define se o alvo esta a esquerda ou a direita
void Anjo::EncontraPosAlvo()
{
    if (jogadoresAtivos == "Dois")
        alvo = verificaMaisProximo(player1, player2, getPosicao());

    else if (jogadoresAtivos == "Jogador1")
        alvo = player1;

    else if (jogadoresAtivos == "Jogador2")
        alvo = player2;

    else if (jogadoresAtivos == "Nenhum")
        cout << "Nenhum Jogador vivo | Anjo.cpp (EncontraPosAlvo)" << endl;

    posAlvo = alvo->getPosicao();

    Vector2f diferenca = (getPosicao() - posAlvo);

    if (diferenca.x < 0.00f)
        direcao_alvo = "direita";
    else
        direcao_alvo = "esquerda";
    
}

//atira o projetil referente a pos o alvo
void Anjo::atirar_projetil()
{
      
    //Lanca de 1 em 1s
    
    //Liberar projetil
    if (estaNoRaio || projetil->getRepouso() == false) {
        EncontraPosAlvo();

        if (projetil)
            projetil->atirar(direcao_alvo, tempo_atk);

    }
    
}

//O anjo de movimenta 
void Anjo::Mover()
{
    movGravidade();

    qualPerseguir(getPosicao());

}


void Anjo::Executar()
{
    verificaVida();
    Mover();
    atirar_projetil();

}

//
void Anjo::Colisao(Entidade* entidade, Vector2f inter_colisao)
{
	ID id_entidade = entidade->getId();

    if (id_entidade == jogador)
    {

        //Ataque (So ataca quando o jogador nao tiver em cima)
        Personagens* jogador = static_cast<Personagens*>(entidade);

        jogadorEmCima = jogador->getEmCima();

        if (!jogadorEmCima)
        {
            if (jogador->getEstadoMovimentoJogador() == true)
            {

                if (jogador->getOlhar())
                {
                    jogador->movimentaEntidade(repulsao_esquerda, false);
                }
                else if (!jogador->getOlhar())
                {
                    jogador->movimentaEntidade(repulsao_direita, true);
                }
            }
            else
            {
                if (olhandoDireita)
                {
                    jogador->movimentaEntidade(repulsao_direita, true);
                }
                else if (olhandoEsquerda)
                {
                    jogador->movimentaEntidade(repulsao_esquerda, false);
                }
            }
            atacar(jogador, dano);
            jogador->atacar(this, jogador->getDano());
        }    
    }
    else
        corrigeColisoes(entidade, inter_colisao);
}


