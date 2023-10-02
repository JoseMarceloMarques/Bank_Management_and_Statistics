#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "clientes.h"
#include "contas.h"


void guardarConta(NodoCon **listaCon, Conta dadosCon){
	NodoCon *aux;
	aux=(NodoCon*)malloc(sizeof(NodoCon));
	aux->auxCon=dadosCon;
	aux->next=*listaCon;
	*listaCon=aux;
}

int existeConta(int codigoConta, NodoCli *listaCli){
	NodoCli *auxCliente;
	NodoCon *auxConta;
	auxCliente=listaCli;
	int encontrou = 0;
		
	while(encontrou==0 && auxCliente!=NULL){
		auxConta=auxCliente->auxCli.contas;
		while(encontrou==0 && auxConta!=NULL){
			if(codigoConta==auxConta->auxCon.codigoCon){
				encontrou=1;
			}
			else{
				auxConta=auxConta->next;
			}	
		}
		auxCliente=auxCliente->next;
	}
	return encontrou;
}

void criarConta(Conta *dadosCon, NodoCli **listaCli){
	int opcao;
	Cliente *cliCriarConta;
	cliCriarConta = procuraCliente(*listaCli);
	
	if(cliCriarConta != NULL){
		printf("\nCódigo da conta a criar: ");
		scanf("%d",&dadosCon->codigoCon);
		fflush(stdin);
		do{
			printf("\nTIPO DE CONTA\n1 - Conta à Ordem\n2 - Conta a Prazo\nEscolha o número correspondente ao tipo de conta que quer criar\n");
			scanf("%d", &opcao);
			switch(opcao){
				case 1:
					strcpy(dadosCon->tipo, "Ordem");
				break;
				case 2:
					strcpy(dadosCon->tipo, "Prazo");
				break;
				default: printf("Opção inválida");
			}	
		}while(opcao != 1 && opcao != 2);
		
		dadosCon->saldo=0;
		dadosCon->movimentos=NULL;
		
		if(existeConta((*dadosCon).codigoCon, *listaCli) == 0){
			guardarConta(&cliCriarConta->contas, *dadosCon);
			printf("\nConta criada com sucesso\n");	
		}else{
			printf("\nA conta com esse código já existe\n");
		}		
	}
	getch();
}

Conta* procuraConta(Cliente *cliConta){
	long codProcurar;
	int encontrou=0;
	NodoCon *aux;
	aux=cliConta->contas;
	Conta *conEncontrada = NULL;
	
	printf("\nIndique a conta: ");
	scanf("%d", &codProcurar);
	while(encontrou==0 && aux!=NULL){
		if(codProcurar==aux->auxCon.codigoCon){
			encontrou=1;
			conEncontrada = (&aux->auxCon);
		} 
		else{
			aux=aux->next;
		}	
	}
	if(encontrou==0){
		printf("\nA conta não Existe");
	}	
	return conEncontrada;
}


void editarConta(NodoCli *listaCli){
	int opcao;
	NodoCli *aux;
	Cliente *cliEditar;
	Conta *conEditar;
	
	cliEditar = procuraCliente(listaCli);
	if(cliEditar!=NULL){
		conEditar = procuraConta(cliEditar);
		if(conEditar != NULL){
			do{
				printf("\nTIPO DE CONTA\n1 - Conta à Ordem\n2 - Conta a Prazo\nEscolha o número correspondente ao tipo de conta que quer criar\n");
				scanf("%d", &opcao);
				switch(opcao){
					case 1:
						strcpy(conEditar->tipo, "Ordem");
					break;
					case 2:
						strcpy(conEditar->tipo, "Prazo");
					break;
					default: printf("Opção inválida");
				}
			}while(opcao != 1 && opcao != 2);
		}
	}
	getch();
}

void contaCli(NodoCli *listaCli){
	Cliente *cliEncontrar;
	Conta *conEncontrar;
	
	cliEncontrar = procuraCliente(listaCli);
	if(cliEncontrar!=NULL){
		conEncontrar = procuraConta(cliEncontrar);	
		if(conEncontrar != NULL){
			printf("\n|---------------------------------------------------|\n\tTipo da conta:  %s\t\n\tSaldo da conta: %.2f\t\n|---------------------------------------------------|", conEncontrar->tipo, conEncontrar->saldo);
		}
	}
	getch();
}

void removerConta(NodoCli **listaCli){
	NodoCon *aux, *ant;
	Cliente *cliEncontrar;
	int codProcurar, encontrou=0;;
	
	cliEncontrar = procuraCliente(*listaCli);	
	if(cliEncontrar!=NULL){
		aux=cliEncontrar->contas;
		ant=cliEncontrar->contas;
		
		printf("\nIndique o código da conta a eliminar: ");
		scanf("%d", &codProcurar);
		
		while(encontrou==0 && aux!=NULL){
			if(codProcurar==aux->auxCon.codigoCon){
				if(ant == aux && aux == cliEncontrar->contas){
					cliEncontrar->contas = aux->next;
				}else{
					ant->next=aux->next;
				}
				free(aux);
				aux = NULL;
				printf("\nA conta foi removida\n");
				encontrou=1;
			}
			else{
				ant = aux;
				aux=aux->next;
			}
		}
		if(encontrou==0){
			printf("\nA conta não Existe");
		}
	}
	getch();
}

void listarContasCliente(NodoCli *listaCli){
	Cliente *cliListarConta;
	NodoCon *listaCon;
	
	cliListarConta = procuraCliente(listaCli);
	if(cliListarConta != NULL){
		listaCon = cliListarConta->contas;
		if(listaCon!=NULL){
			printf("\nCód. Conta\tTipo\tSaldo");
			printf("\n----------------------------------------------");
			while(listaCon!=NULL){
				printf("\n%d\t\t%s\t\t%.2f",listaCon->auxCon.codigoCon,listaCon->auxCon.tipo,listaCon->auxCon.saldo);
				listaCon = listaCon->next;
			}
		}else{
			printf("\nEste cliente não tem nenhuma conta\n");
		}
	}
	getch();
}

int contaOrdem(Cliente **cliente, NodoCli *listaCli){
	NodoCli *aux;
	NodoCon *listaCon;
	int estado = 0;
	
	*cliente = procuraCliente(listaCli);
	if(cliente != NULL){
		listaCon = (*cliente)->contas;
		while(listaCon!=NULL){
			if(strcmp(listaCon->auxCon.tipo, "Ordem") == 0){
				estado = 1;
			}
			listaCon = listaCon->next;
		}
	}
	return estado;
}

int contaPrazo(Cliente **cliente, NodoCli *listaCli){
	NodoCli *aux;
	NodoCon *listaCon;
	int estado = 0;
	
	*cliente = procuraCliente(listaCli);
	if(cliente != NULL){
		listaCon = (*cliente)->contas;
		while(listaCon!=NULL){
			if(strcmp(listaCon->auxCon.tipo, "Prazo") == 0){
				estado = 1;
			}
			listaCon = listaCon->next;
		}
	}
	return estado;
}



