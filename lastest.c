/* Autoria:
 * 
 * 		Universidade Federal de Pelotas
 * 		Centro de Desenvolvimento Tecnologico
 * 		Bacharelado em Ciência da Computação
 * 		Glauco Roberto Munsberg dos Santos
 * 			glaucomunsberg@gmail.com		
 * 
 * Sobre o Projeto:
 * 		Trabalho desenvolvido como avaliação de Estrutura de Dados 1
 * 		Para maiores informações sobre o projeto,
 * 		ele se encontra disponível pelo endereço http://github.com/glaucomunsberg/PHP
 * 
 */

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
		system("clear");
		printf("Lista de Alocação Seguencial\n	1.Insert\n	2.get\n	3.set\n	4.Delete\n	5.Locate\n	6.Length\n	7.Imprimir\n	0.Sair\nESCOLHA:");
		do
		{
			scanf("%d",&escolha);
		}while( escolha < 0 || escolha > 7);
		switch(escolha)
		{
			case 0: printf("		Saindo do programa...\n");
					exit(0);
					break;
			case 1:
					//--Insert
					printf("\n			Posição: ");
					scanf("%d", &posicao);
					printf("			Valor: ");
					scanf("%d", &chave);
					retorno  = insert(posicao, chave, &descritor);
					if( retorno == 1)
					{
						printf("\n		O valor foi inserido com sucesso.\n");
					}
					else
					{
						printf("		O valor %d não pode ser inserido na posição %d.\n", chave, posicao);
					}
					getchar();getchar();
					break;
			case 2: 
					//--Get
					printf("\n		Posição: ");
					scanf("%d", &posicao);
					ptr = get(posicao, &descritor);
					if( ptr == NULL)
					{
						printf("\n		A posição %d não pode ser acessada.\n", posicao);
					}
					else
					{
						printf("\n		O valor da posição %d é %d.\n", posicao, *ptr);
						printf("\n		O endereço de memoria da posição %d é %p.\n", posicao, ptr);
					}
					getchar();getchar();
					break;
			case 3: 
					//--Set
					printf("\n		Posição: ");
					scanf("%d",&posi);
					printf("\n		Valor: ");
					scanf("%d", &chave);
					retorno = set(posi, chave, &descritor);
					if(retorno == 1)
					{
						printf("\n		O valor foi inserido com sucesso.\n");
					}
					else
					{
						printf("\n		Ooops! O valor %d não pode ser inserido na posição %d", chave, posicao);
					}
					getchar();getchar();
					break;
			case 4: 
					//--Delete
					printf("\n		Posição: ");
					scanf("%d", &posicao);
					retorno = delete(posicao, &descritor);
					if( retorno == 1)
					{
						printf("\n		O valor foi deletado com sucesso.\n");
					}
					else
					{
						printf("\n		A posição %d não pode ser deletada.\n", posicao);
					}
					getchar();getchar();
					break;
			case 5: 
					//--Locate
					printf("\n		Valor: ");
					scanf("%d", &chave);
					ptr = locate(chave, &descritor);
					if( ptr == NULL )
					{
						printf("\n		O valor não existe na lista.\n");
					}
					else
					{
						printf("\n		O valor %d está na posição %p.\n", chave, ptr);
					}
					getchar();getchar();
					break;
			case 6:
					//--Length
					retorno = length( &descritor);
					printf("\n		A Lista tem comprimento %d\n", retorno);
					getchar();getchar();
					break;
			case 7: 
					//--Imprimir
					imprimir( &descritor);
					getchar();getchar();
					break;
			default:
					//--Exit
					printf("Ooops! Você não deveria estar aqui! o.O\n"); 
					exit(0);
		}
		
	}
	return 0;
}

void imprimir(struct desc_lista *descritor)
{
	printf("\n");
	int i;
	if(descritor->position != 0)
	{
		printf("Lista: [");
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
