#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "clientes.h"
#include "contas.h"
#include "movimentos.h"
#include "menus.h"
#include "ficheiros.h"

int main(){
	
	setlocale(LC_ALL, "Portuguese");

	NodoCli *listaCli = NULL;

	int opcao;
	
	do{
		system("cls");
		printf("\n*********** MENU ***********\n\n\nEscolha uma das seguintes opções\n\n1 - CLIENTES\n\n2 - CONTAS\n\n3 - MOVIMENTOS\n\n4 - CONSULTAR\n\n9 - SAIR DO PROGRAMA\n\n");
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao){
			case 1: menuClientes(&listaCli);								
			break;
			case 2: menuContas(&listaCli);
			break;
			case 3: menuMovimentos(&listaCli);				
			break;
			case 4: menuConsultar(&listaCli);
			break;
			case 9: printf("\n\n******** O PROGRAMA VAI TERMINAR ********\n\n");
			break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);

	//free(listaCli);
	
	return 0;
}
