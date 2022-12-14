#pragma once
#include "Personagens.h"

class Jogador :
    public Personagens
{
private:
    
    //sf::Texture tex_jogador;
    //sf::Sprite sprite_jogador;

    int pontuacao;

    sf::Clock tempo;
    void iniciar();
    
public:
    Jogador();
    ~Jogador();

    //Sistema de pontos
    void ganhaPontos(int pontos);
    void ganhaPontos();
    void perdePontos(int pontos);
    void perdePontos();
    const int getPontos();

    
    //Movimento
    virtual void Mover();
    void andar(int i);
    
    //Colisao
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao);

    //Atualiza
    virtual void Executar();

};

