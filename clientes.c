#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "clientes.h"	

Cliente* procuraCliente(NodoCli *listaCli){
	long codProcurar;
	int encontrou=0;
	NodoCli *aux;
	aux=listaCli;
	Cliente *cliEncontrado = NULL;
	
	printf("\nIndique o código do cliente: ");
	scanf("%d", &codProcurar);
	while(encontrou==0 && aux!=NULL){
		if(codProcurar==aux->auxCli.codigoCli){
			encontrou=1;
			cliEncontrado = (&aux->auxCli);
		} 
		else{
			aux=aux->next;
		}	
	}
	if(encontrou==0){
		printf("\nO cliente não Existe");
	}	
	return cliEncontrado;
}
	
void dadosCliente(Cliente *dadosCli){
	printf("\nCódigo do cliente: ");
	scanf("%ld",&dadosCli->codigoCli);
	printf("Nome: ");
	fflush(stdin);
	gets(dadosCli->nome);
	printf("Morada: ");
	fflush(stdin);
	gets(dadosCli->morada);
	dadosCli->saldo=0;
	dadosCli->contas = NULL;
}

int existeCliente(long codigoCliente, NodoCli *listaCli){
	NodoCli *aux;
	aux=listaCli;
	int encontrou = 0;
		
	while(encontrou==0 && aux!=NULL){
		if(codigoCliente==aux->auxCli.codigoCli){
			encontrou=1;
		} 
		else{
			aux=aux->next;
		}	
	}
	return encontrou;
}

void guardarCliente(NodoCli **listaCli, Cliente dadosCli){
	NodoCli *aux;
	aux=(NodoCli*)malloc(sizeof(NodoCli));
	aux->auxCli=dadosCli;
	aux->next=*listaCli;
	*listaCli=aux;
	printf("\nCliente criado com sucesso\n");
	getch();
}

void editarCliente(NodoCli *listaCli){
	NodoCli *aux;
	Cliente *cliEditar;
	
	cliEditar = procuraCliente(listaCli);

	if(cliEditar != NULL){
		printf("\nNova nome: ");
		fflush(stdin);
		gets(cliEditar->nome);
		printf("\nNova morada: ");
		fflush(stdin);
		gets(cliEditar->morada);
	}
	getch();
}

void saldoGlobalCliente(NodoCli *listaCli){
	long codProcurar;
	int encontrou=0;
	NodoCli *aux;
	aux=listaCli;
	
	printf("\nIndique o código do cliente a consultar o saldo: ");
	scanf("%d", &codProcurar);
	while(encontrou==0 && aux!=NULL){
		if(codProcurar==aux->auxCli.codigoCli){
			printf("\n|---------------------------------------------------|\n\tSaldo global do cliente: %.2f\t\n|---------------------------------------------------|",aux->auxCli.saldo);
			encontrou=1;
		} 
		else{
			aux=aux->next;
		}	
	}
	if(encontrou==0){
		printf("\nO cliente não Existe");
	}
	getch();
}

void removerCliente(NodoCli **listaCli){
	
	long codProcurar;
	int encontrou=0;
	NodoCli *aux, *ant;
	aux=*listaCli;
	ant=*listaCli;
	
	printf("\nIndique o código do cliente a eliminar: ");
	scanf("%d", &codProcurar);
	while(encontrou==0 && aux!=NULL){
		if(codProcurar==aux->auxCli.codigoCli){
			if(ant == aux && aux == *listaCli){
				*listaCli = aux->next;
			}else{
				ant->next=aux->next;
			}
			
			free(aux);
			aux = NULL;
			printf("\nO cliente foi removido\n");
			encontrou=1;
		}
		else{
			ant = aux;
			aux=aux->next;
		}	
	}
	if(encontrou==0){
		printf("\nO cliente não Existe");
	}
	getch();
}



void listarClientes(NodoCli *listaCli){
	NodoCli *aux;
	aux=listaCli;
	
	if(aux!=NULL){
		printf("\nCód. Cliente\tNome\t\tMorada\t\tSaldo");
		printf("\n-------------------------------------------------------------");
		while(aux!=NULL){
			printf("\n%ld\t\t%s\t\t%s\t\t%.2f",aux->auxCli.codigoCli,aux->auxCli.nome,aux->auxCli.morada,aux->auxCli.saldo);
			aux=aux->next;
		}
	}else{
		printf("\nNão existem clientes para listar\n");
	}
	getch();
}
