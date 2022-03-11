#include <iostream>
#include "No.h"
#include "ArvoreBST.h"

using namespace std;

int main()
{
	ArvoreBST arv;
	int opcao, x;
	cout << ("\nTestando o TAD BST (Elementos do tipo int)\n");

	do
	{
		cout << "\n\n";
		cout << "\n***********************************";
		cout << "\n\tMenu - Arvore BST\n";
		cout << "\nEntre com a opcao:";
		cout << "\n ----1: Inserir";
		cout << "\n ----2: Excluir";
		cout << "\n ----3: Pesquisar";
		cout << "\n ----4: Imprimir em ordem";
		cout << "\n ----5: Qde de nos";
		cout << "\n ----6: Altura";
		cout << "\n ----7: Sair do programa\n";
		cout << "\n***********************************";
		cout << "\n-> ";
		cin >> opcao;
		switch (opcao)
		{
		case 1:
		{
			cout << "\n Informe o valor (int) -> ";
			cin >> x;
			arv.inserir(x);
			break;
		}
		case 2:
		{
			cout << "\n Ainda nao implementado! ";

			break;
		}
		case 3:
		{
			cout << "\n Informe o valor da chave (int) -> ";
			cin >> x;
			// No *ret = arv.Pesquisar(x,arv.getRaiz());
			No *ret = arv.PesquisarRec(arv.getRaiz(), x);
			if (ret == NULL)
			{
				cout << "\n Chave nao encontrada! ";
			}
			else
			{
				cout << "\n Chave encontrada! ";
			}
			break;
		}
		case 4:
		{
			cout << "Percorrendo em ordem...\n";
			arv.emOrdem(arv.getRaiz());
			break;
		}
		case 5:
		{
			cout << "Qde de nos: " << arv.contarNos(arv.getRaiz());
			break;
		}
		case 6:
		{
			cout << "Altura da Arvore: " << arv.altura(arv.getRaiz());
			break;
		}
		default:
			if (opcao != 7)
				cout << "\n Opcao invalida! \n\n\n";
		} // fim switch
	} while (opcao != 7);

	return 0;
}