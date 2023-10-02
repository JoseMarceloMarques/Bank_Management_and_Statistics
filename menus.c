#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "clientes.h"
#include "contas.h"
#include "movimentos.h"
#include "menus.h"


void menuClientes(NodoCli **listaCli){
	int opcao;
	Cliente dadosCli;
	int existeCli;
	
	do{
		system("cls");
		printf("\n******* MENU CLIENTES *******\n\n1 - CRIAR CLIENTE\n\n2 - EDITAR CLIENTE\n\n3 - CONSULTAR SALDO DO CLIENTE\n\n4 - REMOVER CLIENTE\n\n5 - LISTAR CLIENTES\n\n9 - VOLTAR AO MENU PRINCIPAL\n\n");
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao){
			case 1: 
				dadosCliente(&dadosCli);
				if(existeCliente(dadosCli.codigoCli, *listaCli) == 0){
					guardarCliente(listaCli, dadosCli);
				}else{
					printf("\nO cliente com esse código já existe");
					getch();
				}
			break;
			case 2:
				editarCliente(*listaCli);
			break;
			case 3:
				saldoGlobalCliente(*listaCli);
			break;
			case 4:
				removerCliente(listaCli);
			break;
			case 5:
				listarClientes(*listaCli);
			break;
			case 9:	break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);
}

void menuContas(NodoCli **listaCli){
	int opcao;
	Conta dadosCon;
	
	do{
	 	system("cls");
		printf("\n******* MENU CONTAS *******\n\n1 - CRIAR CONTA\n\n2 - EDITAR CONTA\n\n3 - CONSULTAR CONTA DO CLIENTE\n\n4 - REMOVER CONTA\n\n5 - LISTAR CONTAS\n\n9 - VOLTAR AO MENU PRINCIPAL\n\n");
		scanf("%d", &opcao);
		system("cls");	

		switch(opcao){
			case 1: 
				criarConta(&dadosCon, listaCli);
			break;
			case 2: 
				editarConta(*listaCli);
			break;
			case 3:
				contaCli(*listaCli);
			break;
			case 4:
				removerConta(listaCli);
			break;
			case 5:
				listarContasCliente(*listaCli);
			break;
			case 9:	break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);
}

void menuMovimentos(NodoCli **listaCli){
	int opcao, estado;
	Cliente *cliente;
	
	do{
		system("cls");
		printf("\n******* MENU MOVIMENTOS *******\n\n1 - ORDEM\n\n2 - PRAZO\n\n3 - Ver Movimentos\n\n9 - VOLTAR AO MENU PRINCIPAL\n\n");
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao){
			case 1: estado = contaOrdem(&cliente, *listaCli);
					if(estado != 1){
						printf("\nO cliente não tem nenhuma conta à ordem\n");
						getch();
					}else{
					menuMovimentosOrdem(listaCli, cliente);
					}
			break;
			case 2: estado = contaPrazo(&cliente, *listaCli);
					if(estado != 1){
						printf("\nO cliente não tem nenhuma conta a prazo\n");
						getch();
					}else{
					menuMovimentosPrazo(listaCli, cliente);
					}
			break;
			case 3: listaMovimento(*listaCli);
			case 9:	break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);
}

void menuMovimentosOrdem(NodoCli **listaCli, Cliente *cliente){
	int opcao;
	Movimento dadosMov;
	
	do{
		system("cls");
		printf("\n******* MENU Movimentos *******\n\n1 - DEPOSITAR\n\n2 - LEVANTAR\n\n9 - VOLTAR ATRÁS\n\n");
		scanf("%d", &opcao);
		system("cls");
		switch(opcao){
			case 1: criarDepositoOrdem(&dadosMov, listaCli, cliente);
			break;
			case 2: criarLevantamentoOrdem(&dadosMov, listaCli, cliente);
			break;
			case 9:	break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);
}

void menuMovimentosPrazo(NodoCli **listaCli, Cliente *cliente){
	int opcao;
	Movimento dadosMov;
	
	do{
		system("cls");
		printf("\n******* MENU Movimentos *******\n\n1 - DEPOSITAR\n\n2 - LEVANTAR\n\n9 - VOLTAR ATRÁS\n\n");
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao){
			case 1: criarDepositoPrazo(&dadosMov, listaCli, cliente);
			break;
			case 2: criarLevantamentoPrazo(&dadosMov, listaCli, cliente);
			break;
			case 9:	break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);
}

void menuConsultar(NodoCli **listaCli){
	int opcao;
	
	do{
		system("cls");
		printf("\n******* MENU CONSULTAR *******\n\n1 - Lista de clientes por saldo\n\n2 - Lista de clientes por localidade\n\n3 - Lista de clientes com saldo negativo\n\n9 - VOLTAR AO MENU PRINCIPAL\n\n");
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao){
			case 1: clientesRanking(*listaCli);
			break;
			case 2: clientesLocalidade(*listaCli);
			break;
			case 3: clientesSaldoNegativo(*listaCli);
			break;
			case 9:	break;
			default: printf("Opção inválida");
		}
	}while(opcao!=9);
}
