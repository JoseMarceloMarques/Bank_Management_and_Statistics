#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "clientes.h"
#include "contas.h"
#include "movimentos.h"

void guardarMovimento(NodoMov **listaMov, Movimento dadosMov){
	NodoMov *aux;
	aux=(NodoMov*)malloc(sizeof(NodoMov));
	aux->auxMov=dadosMov;
	aux->next=*listaMov;
	*listaMov=aux;
}

void devolveData(char* dataAtual){
	struct tm *data;
	time_t tempoBruto;
	
	time(&tempoBruto);
	data = localtime(&tempoBruto);
	sprintf(dataAtual,"%d/%d/%d", data->tm_mday,data->tm_mon+1,data->tm_year+1900);
}

void criarDepositoOrdem(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente){
	int opcao;
	float saldo;
	Conta *conCriarMov;
	
	conCriarMov = procuraConta(cliente);	
	if(conCriarMov != NULL){
		if(strcmp(conCriarMov->tipo, "Ordem") == 0){
			devolveData(dadosMov->data);
			do{
				printf("\nTIPO DE MOVIMENTO\n1 - Crédito\n2 - Débito\nEscolha o número correspondente ao tipo de movimento que pretende utilizar\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						strcpy(dadosMov->tipo, "Crédito");
					break;
					case 2:
						strcpy(dadosMov->tipo, "Débito");
					break;
					default: printf("Opção inválida");
				}	
			}while(opcao != 1 && opcao != 2);
			do{
				printf("\nMontante a depositar: ");
				scanf("%f",&saldo);
				if(saldo>0){
					dadosMov->valor=saldo;
					fflush(stdin);
				}else{
					printf("O valor a depositar tem de ser positivo");
				}
			}while(saldo<=0);
			conCriarMov->saldo = conCriarMov->saldo + saldo;
			cliente->saldo = cliente->saldo + saldo;
			guardarMovimento(&cliente->contas->auxCon.movimentos, *dadosMov);
			printf("\nOperação efetuada com sucesso");
		}else{
			printf("\nEsta conta não é à ordem\n");
		}
	}
	getch();
}

void criarDepositoPrazo(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente){
	int opcao;
	float saldo;
	Conta *conCriarMov;
	
	conCriarMov = procuraConta(cliente);	
	if(conCriarMov != NULL){
		if(strcmp(conCriarMov->tipo, "Prazo") == 0){
			devolveData(dadosMov->data);
			do{
				printf("\nTIPO DE MOVIMENTO\n1 - Crédito\n2 - Débito\nEscolha o número correspondente ao tipo de movimento que pretende utilizar\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						strcpy(dadosMov->tipo, "Crédito");
					break;
					case 2:
						strcpy(dadosMov->tipo, "Débito");
					break;
					default: printf("Opção inválida");
				}	
			}while(opcao != 1 && opcao != 2);
			do{
				printf("\nMontante a depositar: ");
				scanf("%f",&saldo);
				if(saldo>0){
					dadosMov->valor=saldo;
					fflush(stdin);
				}else{
					printf("O valor a depositar tem de ser positivo");
				}
			}while(saldo<=0);
			conCriarMov->saldo = conCriarMov->saldo + saldo;
			cliente->saldo = cliente->saldo + saldo;
			guardarMovimento(&cliente->contas->auxCon.movimentos, *dadosMov);
			printf("\nOperação efetuada com sucesso");
		}else{
			printf("\nEsta conta não é a prazo\n");
		}
	}
	getch();
}

void criarLevantamentoOrdem(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente){
	int opcao;
	float saldo;
	Conta *conCriarMov;
	
	conCriarMov = procuraConta(cliente);	
	if(conCriarMov != NULL){
		if(strcmp(conCriarMov->tipo, "Ordem") == 0){
			devolveData(dadosMov->data);
			do{
				printf("\nTIPO DE MOVIMENTO\n1 - Crédito\n2 - Débito\nEscolha o número correspondente ao tipo de movimento que pretende utilizar\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						strcpy(dadosMov->tipo, "Crédito");
					break;
					case 2:
						strcpy(dadosMov->tipo, "Débito");
					break;
					default: printf("Opção inválida");
				}	
			}while(opcao != 1 && opcao != 2);
			do{
				printf("\nMontante a levantar: ");
				scanf("%f",&saldo);
				if(saldo>0){
					dadosMov->valor=saldo;
					fflush(stdin);
				}else{
					printf("O valor a levantar tem de ser positivo");
				}
			}while(saldo<=0);
			conCriarMov->saldo = conCriarMov->saldo - saldo;
			cliente->saldo = cliente->saldo - saldo;
			guardarMovimento(&cliente->contas->auxCon.movimentos, *dadosMov);
			printf("\nOperação efetuada com sucesso");
		}else{
			printf("\nEsta conta não é à ordem\n");
		}
	}
	getch();
}

void criarLevantamentoPrazo(Movimento *dadosMov, NodoCli **listaCli, Cliente *cliente){
	int opcao;
	float saldo;
	Conta *conCriarMov;
	
	conCriarMov = procuraConta(cliente);	
	if(conCriarMov != NULL){
		if(strcmp(conCriarMov->tipo, "Prazo") == 0){
			devolveData(dadosMov->data);
			do{
				printf("\nTIPO DE MOVIMENTO\n1 - Crédito\n2 - Débito\nEscolha o número correspondente ao tipo de movimento que pretende utilizar\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						strcpy(dadosMov->tipo, "Crédito");
					break;
					case 2:
						strcpy(dadosMov->tipo, "Débito");
					break;
					default: printf("Opção inválida");
				}	
			}while(opcao != 1 && opcao != 2);
			do{
				printf("\nMontante a levantar: ");
				scanf("%f",&saldo);
				if(saldo>0){
					dadosMov->valor=saldo;
					fflush(stdin);
				}else{
					printf("O valor a levantar tem de ser positivo");
				}
			}while(saldo<=0);
			conCriarMov->saldo = conCriarMov->saldo - saldo;
			cliente->saldo = cliente->saldo - saldo;
			guardarMovimento(&cliente->contas->auxCon.movimentos, *dadosMov);
			printf("\nOperação efetuada com sucesso");
		}else{
			printf("\nEsta conta não é a prazo\n");
		}
	}
	getch();
}

void listaMovimento(NodoCli *listaCli){
	Cliente *cliEncontrar;
	NodoCon *listaCon;
	Conta *conEncontrar;
	
	cliEncontrar = procuraCliente(listaCli);
	if(cliEncontrar!=NULL){
		conEncontrar = procuraConta(cliEncontrar);	
		if(conEncontrar != NULL){
			printf("\nData\t\tTipo\t\tValor");
			printf("\n---------------------------------------");
			while(conEncontrar->movimentos!=NULL){
				printf("\n%s\t%s\t\t%.2f\n", conEncontrar->movimentos->auxMov.data, conEncontrar->movimentos->auxMov.tipo, conEncontrar->movimentos->auxMov.valor);
				conEncontrar->movimentos=conEncontrar->movimentos->next;
			}
		}
	}
	getch();
}

