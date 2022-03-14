#include <cstdlib>
#include <iostream>
#include <time.h>
#include "No.h"
#include "ArvoreBST.h"

ArvoreBST::ArvoreBST()
{
    raiz = NULL;
}

bool ArvoreBST::ehFolha(No *no){
	return (no->getDir() == NULL && no->getEsq() == NULL);
}

void ArvoreBST::inserir(int chave)
{
    if (raiz == NULL)         // verifica se a arvore esta' vazia
        raiz = new No(chave); // cria um novo no'
    else
        inserirAux(raiz, chave);
}

void ArvoreBST::inserirAux(No *no, int chave)
{
    // se for menor, entao insere a' esquerda
    if (chave < no->getChave())
    {
        // verifica se a esquerda e' nulo
        if (no->getEsq() == NULL)
        {
            No *novo_no = new No(chave);
            no->setEsq(novo_no); // set o novo_no a' esquerda
        }
        else
        {
            // senao, continua percorrendo recursivamente
            inserirAux(no->getEsq(), chave);
        }
    }
    // se for maior, entao insere a' direita
    else if (chave > no->getChave())
    {
        // verifica se a direita e' nulo
        if (no->getDir() == NULL)
        {
            No *novo_no = new No(chave);
            no->setDir(novo_no); // set o novo_no a' direita
        }
        else
        {
            // senï¿½o, continua percorrendo recursivamente
            inserirAux(no->getDir(), chave);
        }
    }
    // se for igual, nao vai inserir
    // nao pode existir 2 chaves iguais
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
    No *atual = no;  // cria ponteiro para aux para no' (atual) e comeca a procurar
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
    if (r == NULL || r->getChave() == k) // Se a Raiz desta Subarvore for NULL ou tem chave k.
        return r; // Retorna este No'
    if (r->getChave() > k) // Se a raiz desta Subarvore for > K
        return PesquisarRec(r->getEsq(), k); // Procura K na subarvore da Direita
    else // Se não
        return PesquisarRec(r->getDir(), k); // Procuta K na subarore da Esquerda
}

// versao recursiva
int ArvoreBST::contarNos(No *atual)
{
	// Se o no entrado nao existir (NULL)
	// Retorna o caso base, 0
    if (atual == NULL)
        return 0;
    else // Se o no nao for NULL
    	// Retorna 1 (Conta esta no')
    	// + contagem da subarvore da esquerda
    	// + contagem da subarvore da direita
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

// versao recursiva
int ArvoreBST::contarFolhas(No *atual)
{
	// Se o no' entrado nao existir (NULL)
	// Retorna o caso base NULL, 0
    if (atual == NULL)
        return 0;
    // Se o no' nao possuir filhos, entao e' um no' folha
    // Retorna o caso base folha, 1
    else if (ehFolha(atual))
        return 1;
    // Se o no' nao e' NULL e nem Folha
    // Percorre as subarvores
	else 
		return contarFolhas(atual->getEsq()) + contarFolhas(atual->getDir());
}

void ArvoreBST::printArvore(const string &base, No *atual, bool ehEsquerda, bool ehRaiz)
{
    if( atual != NULL )
    {
    	// Imprime o delimitador passado recursivamente
    	// E' este cout que cria o efeito de niveis
        cout << base;

		// Imprime E para No' esquerdo e D para no' Direito
		if (ehRaiz)
			cout << ("   R(") ;
		else if (ehEsquerda)
			cout << ("\\--E(") ;
		else
			cout << ("|--D(") ;
        
        // Imprime No' 
		cout << atual->getChave() << ") ";
		if (ehFolha(atual))
			cout << "F";
		cout << endl;

        // Entra proxima subarvore
        if (ehEsquerda) {
	        printArvore(base + "     ", atual->getDir(), false, false);
	        printArvore(base + "     ", atual->getEsq(), true,  false); 
    	} 
    	else {
    		printArvore(base + "|    ", atual->getDir(), false, false);
	        printArvore(base + "|    ", atual->getEsq(), true,  false); 
		}
	}	
}

void ArvoreBST::printArvore(No *raiz)
{
	if (raiz == NULL)
		cout << "Arvore Vazia!\n";
    printArvore("", raiz, true, true);    
}

void ArvoreBST::arvoreAleatoria(int qntElementos)
{
	srand((unsigned)time(NULL)); //Criacao da seed para geracao dos numeros pseudo-aleatorios
	for (int i = 0; i < qntElementos; i++)
	{
		this->inserir((rand() % 30) +1);
	}
}

int ArvoreBST::getMax()
{
	if (raiz == NULL)
		cout << "Arvore Vazia!\n";
	No* atual = this->getRaiz();
	while (atual->getDir() != NULL){
		atual = atual->getDir();
	}
	return  atual->getChave();
}

int ArvoreBST::getMin()
{
	if (raiz == NULL)
		cout << "Arvore Vazia!\n";
	No* atual = this->getRaiz();
	while (atual->getEsq() != NULL){
		atual = atual->getEsq();
	}
	return  atual->getChave();
}
// ATIVIDADES INICIAIS DE LAB:
// pesquisar()
// qdeNos()
// alturaArvore()

// PROXIMAS ATIVIDADES DE LAB:
// contarFolhas()
// valorMin()
// valorMax()
// remover()
