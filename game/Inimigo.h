#pragma once

#include "Jogador.h"

class Inimigo : public Personagens
{
private:
    sf::Clock tempo_mov;
    int movRandom;

protected:
    Vector2f raio_deteccao;
    
    Jogador* player1;
    Jogador* player2;

    string jogadoresAtivos;
    bool jogadorEmCima;

    bool estaNoRaio;

    /* Futuramente uma sprite */
    
    //sf::Texture j_textura;
    //sf::Sprite j_sprite;

public:
    Inimigo();
    ~Inimigo();
    
    //Controle
    string verficaJogadoresAtivos(Jogador* j1, Jogador* j2);

    //Movimentos
    void movAleatorio();
    void qualPerseguir(Vector2f pos_inimigo);
    void perseguirUmJogador(Jogador* j, Vector2f posInimimgo);
    void persegurDoisJogadores(Vector2f pos_j1, Vector2f pos_j2, Vector2f pos_inimigo);
    Personagens* verificaMaisProximo(Jogador* j1, Jogador* j2, Vector2f pos_inimigo);
    bool verificaEntidadeNoRaio(Vector2f pos_entidade, Vector2f pos_inimigo, Vector2f raio);

    void PersegueJogador(Vector2f posJogador, Vector2f posInimimgo);
    void podePerseguir(Personagens* personagem);

           
    virtual void Mover() = 0;
    virtual void Executar() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

    //Futuramente talvez seja útil ter uma função que inicializa as variáveis
    //void initVariables();
};

