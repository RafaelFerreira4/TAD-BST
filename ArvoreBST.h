#include <cstdlib>
#include <iostream>
#include "No.h"

using namespace std;
class ArvoreBST
{
private:
    No *raiz;
    bool ehFolha(No* no);
    void printArvore(const string &base, No *atual, bool ehEsquerda, bool ehRaiz);
    void inserirAux(No *raiz, int chave);
    void clear(No *raiz);

public:
    ArvoreBST();
    void printArvore(No *raiz);
    void inserir(int chSave);
    No *getRaiz();
    void emOrdem(No *no);
    void preOrdem(No *no);
    void posOrdem(No *no);
    No *Pesquisar(int dado, No *no);
    No *PesquisarRec(No *r, int k);
    int contarNos(No *atual);
    int contarFolhas(No *atual);
    int altura(No *atual);
    void arvoreAleatoria(int qtdElementos);
    int getMax();
    int getMin();
    void clear();
    void banana(int chave);
};
