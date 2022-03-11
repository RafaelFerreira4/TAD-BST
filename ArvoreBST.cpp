#include <cstdlib>
#include <iostream>
#include "No.h"
#include "ArvoreBST.h"

ArvoreBST::ArvoreBST()
{
    raiz = NULL;
}

void ArvoreBST::inserir(int chave)
{
    if (raiz == NULL)         // verifica se a �rvore est� vazia
        raiz = new No(chave); // cria um novo n�
    else
        inserirAux(raiz, chave);
}

void ArvoreBST::inserirAux(No *no, int chave)
{
    // se for menor, ent�o insere � esquerda
    if (chave < no->getChave())
    {
        // verifica se a esquerda � nulo
        if (no->getEsq() == NULL)
        {
            No *novo_no = new No(chave);
            no->setEsq(novo_no); // seta o novo_no � esquerda
        }
        else
        {
            // sen�o, continua percorrendo recursivamente
            inserirAux(no->getEsq(), chave);
        }
    }
    // se for maior, ent�o insere � direita
    else if (chave > no->getChave())
    {
        // verifica se a direita � nulo
        if (no->getDir() == NULL)
        {
            No *novo_no = new No(chave);
            no->setDir(novo_no); // seta o novo_no � direita
        }
        else
        {
            // sen�o, continua percorrendo recursivamente
            inserirAux(no->getDir(), chave);
        }
    }
    // se for igual, n�o vai inserir
    // n�o pode existir 2 chaves iguais
}

No *ArvoreBST::getRaiz()
{
    return raiz;
}

void ArvoreBST::emOrdem(No *no)
{
    if (no != NULL)
    {
        emOrdem(no->getEsq());
        cout << no->getChave() << " ";
        emOrdem(no->getDir());
    }
}

void ArvoreBST::preOrdem(No *no)
{
    if (no != NULL)
    {
        cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBST::posOrdem(No *no)
{
    if (no != NULL)
    {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getChave() << " ";
    }
}

// versao iterativa
No *ArvoreBST::Pesquisar(int dado, No *no)
{
    if (raiz == NULL)
        return NULL; // arvore vazia
    No *atual = no;  // cria ptr aux (atual) e comeca a procurar
    while (atual->getChave() != dado)
    {
        if (dado < atual->getChave())
            atual = atual->getEsq(); // caminha para esquerda
        else
            atual = atual->getDir(); // caminha para direita
        if (atual == NULL)
            return NULL; // encontrou uma folha e nao encontrou a chave
    }
    return atual; // encontrou o dado
}

// versao recursiva
No *ArvoreBST::PesquisarRec(No *r, int k)
{
    if (r == NULL || r->getChave() == k)
        return r;
    if (r->getChave() > k)
        return PesquisarRec(r->getEsq(), k);
    else
        return PesquisarRec(r->getDir(), k);
}

// versao recursiva
int ArvoreBST::contarNos(No *atual)
{
    if (atual == NULL)
        return 0;
    else
        return (1 + contarNos(atual->getEsq()) + contarNos(atual->getDir()));
}

// versao recursiva
int ArvoreBST::altura(No *atual)
{
    if (atual == NULL)
        return -1;
    else
    {
        if (atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0;
        else
        {
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return (1 + altura(atual->getEsq()));
            else
                return (1 + altura(atual->getDir()));
        }
    }
}

// ATIVIDADES INICIAIS DE LAB:
// pesquisar()
// qdeNos()
// alturaArvore()

// PROXIMAS ATIVIDADES DE LAB:
// ContarFolhas()
// ValorMin()
// ValorMax()
