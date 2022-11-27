#pragma once
#include "Personagens.h"

class Jogador :
    public Personagens
{
private:
    
    //sf::Texture tex_jogador;
    //sf::Sprite sprite_jogador;

    static int pontuacao_j1;
    static int pontuacao_j2;

    //Indica qual jogador ele é (Pode ser um ou dois)
    int tipoJogador;

    sf::Clock tempo;
    void iniciar();

    //Textura do jogador
    sf::Texture texture;

    
public:
    Jogador(int jogador);
    ~Jogador();

    void setTextura();
    

    //Sistema de pontos
    static void setPontos(int pontos_j1, int pontos_j2);
    static const int getPontos(int tipoJogador);

    //Redefinindo função do ataque
    virtual void atacar(Entidade* adversario, float dano);
    //Movimento
    virtual void Mover();
    void andar(int i);
    
    //Colisao
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

    //Atualiza
    virtual void Executar();

    //Def a textura
   // void setTextura();
};

