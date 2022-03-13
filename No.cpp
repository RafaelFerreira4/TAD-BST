#include "No.h"

No::No(int chave)
{
    this->chave = chave;
    esq = NULL;
    dir = NULL;
}

int No::getChave() // Retorna a Chave do No'
{
    return chave;
}

No* No::getEsq() // Retorna No' filho a' esquerda
{
    return esq;
}

No* No::getDir() // Retorna No' filho a' direita
{
    return dir;
}

void No::setEsq(No *no) // Set no' filho a esquerda
{
    esq = no;
}

void No::setDir(No *no) // Set no' filho a direita
{
    dir = no;
}

