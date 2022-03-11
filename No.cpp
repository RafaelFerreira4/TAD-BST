#include "No.h"

No::No(int chave)
{
    this->chave = chave;
    esq = NULL;
    dir = NULL;
}

int No::getChave()
{
    return chave;
}

No* No::getEsq()
{
    return esq;
}

No* No::getDir()
{
    return dir;
}

void No::setEsq(No *no)
{
    esq = no;
}

void No::setDir(No *no)
{
    dir = no;
}

