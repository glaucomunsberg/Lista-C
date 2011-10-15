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
 */

#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

void imprimir(struct desc_lista *descritor);
int main(int argc, char **argv)
{
	//Identificadores e Atribuições----------
	
	int escolha;
	int chave;
	unsigned int retorno;
	int *ptr;
	int posi;
	unsigned int posicao;
	
	struct desc_lista descritor;
	struct nodo *NODO;
	NODO = NULL;
	descritor.tamanho = 0;
	//-------------------------------------
	descritor = *init();
	for(;;)
	{
		system("clear");
		printf("Lista Duplamente Encadeada\n	1.Insert\n	2.get\n	3.set\n	4.Delete\n	5.Locate\n	6.Length\n	7.Imprimir nodo\n	8.Imprimir Lista\n	0.Sair\nESCOLHA: ");
		do
		{
			scanf("%d",&escolha);
		}while( escolha < 0 && escolha >8);
		switch(escolha)
		{
			case 0: printf("\n\nSaindo do programa...\n\n");
					exit(0);
					break;
			case 1:
					printf("\n\nValor:\n");
					scanf("%d", &chave);
					retorno  = insert(NODO, chave, &descritor);
					if( retorno == 1)
					{
						printf("		O valor foi inserido com sucesso!\n");
						//teste
						printf("		HEAD: %p\n		TAIL: %p\n		Valor:%d", descritor.head,descritor.tail,descritor.head->chave);
					}
					else
					{
						printf("Oops! O valor %d não pode ser inserido na posição %d\n", chave, posicao);
					}
					getchar();getchar();
					break;
			case 2: 
					printf("\n\nPosição: ");
					scanf("%d",&posicao);
					NODO = get(posicao, &descritor);
					if( NODO == NULL)
					{
						printf("		Não retornou nada!\n");
					}
					else
					{
						printf("		Retornou.\n");
						//--teste
						printf("Valor %i", NODO->chave);
					}
					getchar();getchar();
					break;
			case 3: 
					if(NODO == NULL)
					{
						printf("	O nodo não foi escolhido!\n");
					}
					else
					{
						scanf("%d", &chave);
						retorno = set(NODO,&chave,&descritor);
						if(retorno == 1)
						{
							printf("		O valor foi alterado com sucesso.\n");
						}
						else
						{
							printf("		O valor não pode ser trocado por causa de um erro.\n");
						}
					}
					getchar();getchar();
					break;
			case 4: 
					break;
			case 5: 
					break;
			case 6:
					retorno = length(&descritor);
					printf("\n\n		O tamanho da lista é de %d\n", retorno);
					getchar();getchar();
					break;
			case 7: 
					break;
			case 8:
					printf("Imprimir");
					imprimir(&descritor);
					getchar();getchar();
					break;
			default: printf("Ooops! Você não deveria estar aqui! o.O"); exit(0);
		}
		
	}
	return 0;
}
void imprimir(struct desc_lista *descritor)
{
	if(descritor->head == NULL)
	{
		printf("Não tem nada no vetor!\n");
	}
	else
	{
		printf("Tem algo aqui e ainda não implementei a impressão!");
	}
}

