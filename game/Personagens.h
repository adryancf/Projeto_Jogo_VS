#pragma once
#include "Entidade.h"

class Personagens : public Entidade
{
protected:

    //Vida
    float q_vida;
    bool vivo;

    //Estado do ataque (true = ja atacou | false = ainda nao atacou)
    bool atacou;

    //Controle do Movimento
    bool podeAndarDireita;
    bool olhandoDireita;
    bool podeAndarEsquerda;
    bool olhandoEsquerda;
    bool podeAndar;
    bool podePular;

    //Controle da repulsao do dragao
    string direcaoMovimento;

public:
    Personagens(const float vida = 5.0);
    ~Personagens();

    //ATAQUE
    virtual void atacar(Entidade* adversario, float dano);
    void setAtacou(bool ataque);
    bool getAtacou();

    //VIDA DO PERSONAGEM
    void setQuantidadeVida(float q);
    const float getQuantidadeVida();
    const bool getVida() const;
    void verificaVida();
    void perdeVida(); //PERDE UMA VIDA | Da para substituir essa funcao por uma sobrecarga de operador
    void perdeVida(float dano); //Perde a vida com base no dano recebido

    //MOVIMENTO E PULO
    void movimentaEntidade(Vector2f mov, bool direcao); // Ja altera as flags de olhar
    void setDirecaoMovimento(string direcao);
    const Vector2<bool> getOlhar(); // Sabemos para aonde a entidade ta olhando
    void verificaPodeAndar(Vector2f pos);
    const Vector2<bool> getPodeAndar();
    void pular(double tam_pulo);
   
    //FUNCOES PRINCIPAIS
    virtual void Executar() = 0;
    virtual void Mover() = 0;
    virtual void Colisao(Entidade* entidade, Vector2f inter_colisao) = 0;

    //Cada personagem atualiza a vida a sua maneira, neste momento comentada pq tem que alterar a classe toda
    //virtual void atualizarVida() = 0;
};

