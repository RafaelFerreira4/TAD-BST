//#ifndef __NO__
//#define __NO__

#ifndef NO_H
#define NO_H

#include <cstdlib>

class No
{
private:
    No *esq, *dir;
    int chave;

public:
    No(int chave);

    // funcoes getters e setters
    int getChave();
    No *getEsq();
    No *getDir();
    void setEsq(No *no);
    void setDir(No *no);
};
#endif
