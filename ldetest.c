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
 * 		ele se encontra disponível no endereço http://github.com/glaucomunsberg/PHP
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
	int flag;
	struct desc_lista descritor;
	struct nodo *NODO;
	NODO = NULL;
	descritor.tamanho = 0;
	flag = 1;
	//-------------------------------------
	
	descritor = *init();
	for(;;)
	{
		system("clear");
		printf("Lista Duplamente Encadeada\n	1.Insert\n	2.Get\n	3.Set\n	4.Delete\n	5.Locate\n	6.Length\n	7.Imprimir Nodo\n	\n	0.Sair\nESCOLHA: ");
		do
		{
			scanf("%d",&escolha);
		}while( escolha < 0 || escolha >7);
		switch(escolha)
		{
			case 0:
					//--Sair
					printf("\n\nSaindo do programa...\n\n");
					exit(0);
					break;
			case 1:
					//--Inserir
					if(flag == 0 && NODO == NULL && descritor.tamanho > 0)
					{
						printf("		Nodo não escolhido.\n");
						getchar();getchar();
						break;
					}
					printf("\n\n		Valor:");
					scanf("%d", &chave);
					retorno  = insert(NODO, chave, &descritor);
					if( retorno == 1)
					{
						printf("		O valor foi inserido com sucesso!\n");
						flag = 0;
					}
					else
					{
						printf("		Oops! O valor %d não pode ser inserido na posição %d\n", chave, posicao);
					}
					getchar();getchar();
					imprimir(&descritor);
					getchar();
					break;
			case 2: 
					//--Get
					printf("\n\nPosição: ");
					scanf("%d",&posicao);
					NODO = get(posicao, &descritor);
					if( NODO == NULL)
					{
						printf("		Não exista a posição.\n");
					}
					else
					{
						printf("		Retornou.\n");
					}
					getchar();getchar();
					imprimir(&descritor);
					getchar();
					break;
			case 3: 
					//--Set
					if(NODO == NULL)
					{
						printf("	O nodo não foi escolhido!\n");
					}
					else
					{
						printf("\n\n		Novo valor:");
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
					imprimir(&descritor);
					getchar();
					break;
			case 4: 
					//--Delete
					if( NODO == NULL)
					{
						printf("	O nodo não foi escolhido!\n");
					}
					else
					{
						retorno = remov(NODO,&descritor);
						if(retorno == 1)
						{
							printf("		O valor foi deletado com sucesso.\n");
							NODO = NULL;
						}
						else
						{
							printf("		O valor não pode ser deletado por causa de um erro.\n");
						}
					}
					getchar();getchar();
					imprimir(&descritor);
					getchar();
					break;
			case 5: 
					//--Locate
					if(NODO == NULL)
					{
						printf("	O nodo não foi escolhido!\n");
					}
					else
					{
						printf("\n\n		Valor a procurar:");
						scanf("%d", &chave);
						NODO = locate(chave, NODO);
						if(NODO == NULL)
						{
							printf("		O nodo não foi encontrado.\n");
						}
						else
						{
							printf("		Nodo encontrado.\n");
						}
					}
					getchar();getchar();
					imprimir(&descritor);
					getchar();
					break;
			case 6:
					//--Length
					retorno = length(&descritor);
					printf("\n\n		O tamanho da lista é de %d\n", retorno);
					getchar();getchar();
					imprimir(&descritor);
					getchar();
					break;
			case 7: 
					//--Imprimir Nodo
					retorno = print(NODO);
					if( retorno == 0)
					{
						printf("		O Nodo é nulo.\n");
					}
					getchar();getchar();
					imprimir(&descritor);
					getchar();
					break;
			default: 
					printf("		Ooops! Você não deveria estar aqui! o.O"); 
					exit(0);
		}
		
	}
	return 0;
}
void imprimir(struct desc_lista *descritor)
{
	if(descritor->head == NULL)
	{
		printf("\n\n		%p head<-Lista \n", descritor->head);
		printf("			NO NODO\n");
		printf("	    		    Lista->Tail %p\n", descritor->tail);
	}
	else
	{
		printf("\n\n		%p head<-Lista \n\n", descritor->head);
		struct nodo *temp;
		temp = malloc(sizeof(struct nodo));
		temp = descritor->head;
		int a=1;
		while(a)
		{
			printf("		Nodo: %p\n", temp);
			printf("		%p Prev<-Nodo \n", temp->prev);
			printf("				 %d\n", temp->chave);
			printf("	    	   		Nodo->Next %p\n\n", temp->next);
			temp = temp->next;
			if(temp == NULL)
			{
				a = 0;
			}
		}
		printf("	    		        Lista->Tail %p\n", descritor->tail);
		free(temp);
	}
}

