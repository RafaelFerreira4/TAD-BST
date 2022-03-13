#include <iostream>
#include <conio.h>
#include "No.h"
#include "ArvoreBST.h"


using namespace std;

void print_logo(){
	cout << "                        ...             ....                     "<< endl;
	cout << "                      =*rrr*+==:--:-.:+*rrrr*=                   "<< endl;
	cout << "                    .:%rrrrrrrr@rrrrr%rrrrrrr%=::.               "<< endl;
	cout << "                 -:+%%rrrrrrrrr%rrrrr*rrrrrrrrrrr%.              "<< endl;
	cout << "               -rrrrrrr%rrr%rrrrrrrrrrrrrr%rrrrrr%-              "<< endl;
	cout << "             .:*%rrrrrrrr +===========+ r*r%rrrrrrrr=            "<< endl;
	cout << "           .*rrrrrrrrrrrr |    TAD    | rrrrrrrrrrrr%*r:         "<< endl;
	cout << "           *rrrrrrrrrrrrr |     -     | rrr*rrrrrr%%rrrr**:      "<< endl;
	cout << "        -=+rrrrrrrrrrrrrr |    BST    | rr%rrrrrrr*%%*rrrr*      "<< endl;
	cout << "      :rrrrrrrrrrrrrrrrrr +===========+ *r%r**rrrrr%r*rrr%=      "<< endl;
	cout << "      %rrrrr%rrrrrrrrrrrrrrrr*rrrrrr%r*rrr%rrr%%rr@rrrrrrr%.     "<< endl;
	cout << "      %r*rr*r%rrrrrrrrrrrrrr%%@*::+%rrrrrrrrrrr**rrrr%r%*-       "<< endl;
	cout << "      -*%rrrrr%rr%rrrrrr*r*r@%%%:-*%%%rrrrrr*rrrrrrrr*==         "<< endl;
	cout << "       *rrrrr*rrrrrrrrrrr%. *%r%@%%%r@-.%%%rrrrrrrrrrr.          "<< endl;
	cout << "       =*rr%rrrrrrrrrr%%=+%=+@%r%%%r%% -%%%@%@rrrrrrr*.          "<< endl;
	cout << "         ..=rrrrrrr****+:+%%%%%rrrr%@*:@%%rrr%%%rr%:.            "<< endl;
	cout << "            .:===-        .r%@%%%rr%@@@*===+=-.-::-              "<< endl;
	cout << "                           -@%rr%%%%@@-                          "<< endl;
	cout << "                           -@%r%@@@@@+                           "<< endl;
	cout << "                           :@%r%@@@@@r                           "<< endl;
	cout << "                   :--   -.*@%rr%%%%@@.  .                       "<< endl;
	cout << "               -:=::*===*rr@%%r%rrrr@@r--=*=:=+*==-              "<< endl;
	cout << "               :=+::+r%@@%@%r%%%%%%%%%@@%%r*=::::=:-             "<< endl;
	cout << "                    .---.....-:+r%%@%++*****+:                   "<< endl;
	cout << "                                  .-.                            "<< endl << endl;
	cout << "            Arvore de Binaria de Busca com chaves int            "<< endl << endl;
	cout << " Por:                                                            "<< endl;
	cout << " Igor Soler Cavalcanti - 42013550                                "<< endl;
	cout << " Paloma                                                          "<< endl;
	cout << " Rafael                                                          "<< endl << endl;
	cout << "                 Pressione ENTER para continuar";
	getch();
	system("cls"); // Windows Only
}

int main()
{
	
	print_logo(); // Print primeira tela
	
	ArvoreBST arv;
	int opcao, x;
	
	do  // Loop do Menu
	{
		cout << "\n***********************************";
		cout << "\n\tMenu - Arvore BST\n";
		
		cout << "\nEntre com a opcao:";
		cout << "\n ----0: Sair do programa\n";	// Implementado
		cout << "\n ----1: Inserir"; 			// Implementado
		cout << "\n ----2: Excluir";           	//
		cout << "\n ----3: Pesquisar";			// Implementado
		cout << "\n ----4: Imprimir em ordem";	// Implementado
		cout << "\n ----5: Qde de nos";			// Implementado
		cout << "\n ----6: Altura";				// Implementado
		cout << "\n ----7: Qde de folhas";		// 
		cout << "\n ----8: Valor max";			// 
		cout << "\n ----9: Valor min";			// 
		cout << "\n ---10: Imprimir Formatado"; // OPCIONAL!
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
		case 7:
		{
			cout << "text" ;
			break;
		}
		case 8:
		{
			cout << "text" ;
			break;
		}
		case 9:
		{
			cout << "text" ;
			break;
		}
		case 10:
		{
			cout << "text" ;
			break;
		}
		default:
			if (opcao != 0)
				cout << "\n Opcao invalida! \n\n\n";
		} // fim switch
	} while (opcao != 0);

	return 0;
}
