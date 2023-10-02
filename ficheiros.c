#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientes.h"
#include "contas.h"
#include "movimentos.h"

/*void guardarFicheiro(NodoCli *listaCli){
	FILE *ficheiro;
	
	ficheiro = fopen ("dados.dat", "w");
	if (ficheiro == NULL)
	{
		fprintf(stderr, "\nErro ao abrir o ficheiro\n");
	}else{
		//fwrite (&listaCli, sizeof(struct NodoCli), 1, ficheiro);		
		if(fwrite != 0){
			printf("Ficheiro escrito com sucesso!\n");
		}else{
			printf("Erro ao escrever ficheiro!\n");
		}
	}
	fclose (ficheiro);
	return 0;
}

NodoCli* lerFicheiro(){
	FILE *ficheiro;
	struct NodoCli *listaCli = NULL;
	
	ficheiro = fopen ("person.dat", "r");
	if (ficheiro == NULL)
	{
		fprintf(stderr, "\nErro ao abrir ficheiro\n");
	}else{		
		//fread(&listaCli, sizeof(struct NodoCli), 1, ficheiro);
	}
	fclose (ficheiro);	
	return listaCli;
}*/

