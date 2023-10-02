#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "clientes.h"
#include "contas.h"
#include "movimentos.h"
#include "consultar.h"

int tamanhoListaCliente(NodoCli *listaCli){
	int contador = 0;
	NodoCli *aux;
	aux = listaCli;
	
	while(aux!=NULL){
		contador ++;
		aux=aux->next;
	}
	
	return contador;
}

int maiorSaldo(Cliente **listaCliente, int tamanho){
	float max = -9999999;
	int i, indice=-1;
	
	for(i=0 ; i < tamanho; i++){
		if(listaCliente[i] != NULL && listaCliente[i]->saldo>max){
			max=listaCliente[i]->saldo;
			indice = i;
		}
	}
	
	return indice;
}


void clientesRanking(NodoCli *listaCli){
	NodoCli *aux;
	aux=listaCli;
	int contador=0, i=0, maior;
	int tamanho = tamanhoListaCliente(listaCli);
	Cliente* listaCliente[tamanho];
	Cliente* listaOrdenada[tamanho];
	
	while(aux!=NULL){
		listaCliente[i]=&aux->auxCli;
		aux=aux->next;
		i++;
	}
	
	printf("\nCód. Cliente\tNome\tMorada\t\tSaldo");
	printf("\n-------------------------------------------------------------");
	
	for(i=0; i<tamanho; i++){
		maior =	maiorSaldo(listaCliente, tamanho);
		listaOrdenada[i]=listaCliente[maior];
		listaCliente[maior]=NULL;
		printf("\n%ld\t\t%s\t\t\t%s\t\t%.2f\n", listaOrdenada[i]->codigoCli,listaOrdenada[i]->nome,listaOrdenada[i]->morada,listaOrdenada[i]->saldo);
	}
	getch();
}

void clientesLocalidade(NodoCli *listaCli){
	NodoCli *aux;
	aux=listaCli;
	char localidade[50];
	int contador=0;
	
	if(aux!=NULL){
		printf("Insira a localidade a pesquisar ");
		fflush(stdin);
		scanf("%[^\n]", localidade);
		while(aux!=NULL){
			if(strcmp(localidade, aux->auxCli.morada) == 0){
				printf("\nCód. Cliente\tNome");
				printf("\n------------------------");
				printf("\n%ld\t\t%s\n",aux->auxCli.codigoCli,aux->auxCli.nome);
				contador ++;
			}
			aux=aux->next;
		}
		if(contador ==0){
			printf("\nNão existem clientes residentes em %s\n", localidade);
		}
	}else{
		printf("\nNão existem clientes\n");
	}
	getch();
}

void clientesSaldoNegativo(NodoCli *listaCli){
	NodoCli *aux;
	aux=listaCli;
	int contador=0;
	
	if(aux!=NULL){
		while(aux!=NULL){
			if(aux->auxCli.saldo<0){
				printf("\nCód. Cliente\tNome");
				printf("\n------------------------");
				printf("\n%ld\t\t%s\n",aux->auxCli.codigoCli,aux->auxCli.nome);
				contador++;
			}
			aux=aux->next;
		}
		if(contador ==0){
			printf("\nNão existem clientes com saldo negativo\n");
		}
	}else{
		printf("\nNão existem clientes\n");
	}
	getch();
}
