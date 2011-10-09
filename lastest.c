#include <stdio.h>
#include "las.h"
#include <stdlib.h>


void imprimir(struct desc_lista * descritor);
int main(int argc, char **argv)
{
	printf("Começo...\n");
	desc_lista descritor;
	descritor.position = 0;
	
	
	
	printf("...Fim\n");
	return 0;
}
void imprimir(struct desc_lista * descritor)
{
	int i;
	if(descritor->position != 0)
	{
		printf("Vetor: [");
		for(i=0; i<descritor->position;i++)
		{
			if(i+1 != descritor->position)
			{
				printf("%d,", descritor->vet[i]);
			}
			else
			{
				printf("%d", descritor->vet[i]);
			}
		}
		printf("]\n");
	}
	else
	{
		printf("Vetor: [NULL]\n");
	}
	
}
