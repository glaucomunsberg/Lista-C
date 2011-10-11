#include <stdio.h>
#include <stdlib.h>
#include "las.h"
void imprimir(struct desc_lista *descritor);
void menu(struct desc_lista *descritor);
int main(int argc, char **argv)
{
	
	//----Identificadores & Atribuições----
	int escolha;
	int chave;
	int retorno;
	int *ptr;
	int **ptr1;
	int posi;
	unsigned int posicao;
	desc_lista descritor;
	descritor.position = 0;
	//-------------------------------------
	
	for(;;)
	{
		printf("Lista de Alocação Seguencial\n1.Insert\n2.get\n3.set\n4.Delete\n5.Locate\n6.Length\n7.Imprimir\n0.Sair\nESCOLHA:");
		do
		{
			scanf("%d",&escolha);
		}while( escolha < 0 && escolha >6);
		switch(escolha)
		{
			case 0: printf("Saindo do programa...\n");
					exit(0);
					break;
			case 1:
					system("clear");
					printf("Lista de Alocação Seguencial - INSERT\nPosição:\n");
					scanf("%d", &posicao);
					printf("Valor:\n");
					scanf("%d", &chave);
					retorno  = insert(posicao, chave, &descritor);
					if( retorno == 1)
					{
						printf("O valor foi inserido com sucesso.\n");
					}
					else
					{
						printf("Oops! O valor %d não pode ser inserido na posição %d\n", chave, posicao);
					}
					break;
			case 2: 
					system("clear");
					printf("Lista de Alocação Seguencial - GET\nPosição:\n");
					scanf("%d", &posicao);
					ptr = get(posicao, &descritor);
					if( ptr == NULL)
					{
						printf("Ooops! A posição %d não pode ser acessada.\n", posicao);
					}
					else
					{
						printf("O valor da posição %d é %d\n", posicao, *ptr);
						printf("O endereço de memoria da posição %d é %p.\n", posicao, ptr);
					}
					break;
			case 3: 
					system("clear");
					printf("Lista de Alocação Seguencial - SET\nPosição:\n");
					scanf("%d",&posi);
					printf("Valor:\n");
					scanf("%d", &chave);
					retorno = set(posi, chave, &descritor);
					if(retorno == 1)
					{
						printf("O valor foi inserido com sucesso.\n");
					}
					else
					{
						printf("Ooops! O valor %d não pode ser inserido na posição %d", chave, posicao);
					}
					break;
			case 4: 
					system("clear");
					printf("Lista de Alocação Seguencial - DELETE\nPosição:\n");
					scanf("%d", &posicao);
					retorno = delete(posicao, &descritor);
					if( retorno == 1)
					{
						printf("O valor foi deletado com sucesso.\n");
					}
					else
					{
						printf("Ooops! A posição %d não pode ser deletada.\n", posicao);
					}
					break;
			case 5: system("clear");
					printf("Lista de Alocação Seguencial - LOCATE\nValor:\n");
					scanf("%d", &chave);
					ptr = locate(chave, &descritor);
					if( ptr == NULL )
					{
						printf("O valor não existe na lista.\n");
					}
					else
					{
						printf("O valor %d está na posição %p.\n", chave, ptr);
					}
					break;
			case 6:
					system("clear");
					printf("Lista de Alocação Seguencial - LENGTH\n");
					retorno = length( &descritor);
					printf("A Lista tem comprimento %d\n", retorno);
					break;
			case 7: imprimir( &descritor);
					break;
			default: printf("Ooops! Você não deveria estar aqui! o.O"); exit(0);
		}
		
	}
	return 0;
}

void imprimir(struct desc_lista *descritor)
{
	system("clear");
	printf("Lista de Alocação Seguencial - IMPRIMIR\n");
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
