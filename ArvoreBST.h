#include <cstdlib>
#include <iostream>
#include "No.h"

using namespace std;
class ArvoreBST
{
private:
    No *raiz;

public:
    ArvoreBST();
    void printArvore(No *raiz);
    void printArvore(const string &base, No *atual, bool ehEsquerda, bool ehRaiz);
    void inserir(int chSave);
    void inserirAux(No *raiz, int chave);
    No *getRaiz();
    void emOrdem(No *no);
    void preOrdem(No *no);
    void posOrdem(No *no);
    No *Pesquisar(int dado, No *no);
    No *PesquisarRec(No *r, int k);
    int contarNos(No *atual);
    int contarFolhas(No *atual);
    int altura(No *atual);
};
