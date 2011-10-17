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

#include "lde.h"
#include <stdio.h>
#include <stdlib.h>

struct desc_lista *init()
{
	/*
	 * Entradas:	Não tem
	 *
	 * Função:		Aloca espaço, inicializa lista
	 * 
	 * Saída:		Um ponteiro para um descritor de lista
	 */
	 
	 struct desc_lista *descritor;
	 descritor = (struct desc_lista*) malloc(sizeof(struct desc_lista));
	 descritor->head = NULL;
	 descritor->tail = NULL;
	 descritor->tamanho = 0;
	return descritor;

}
int insert(struct nodo *anterior, int chave, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Nodo 		- Ponteiro do elemento anterior
	 * 				Chave		- Valor da posição que está sendo inserida
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		insere um novo elemento após anterior 
	 * 					(ou no início da lista, se NULL)
	 * 
	 * Saída:		0	- Se houver erro
	 * 				1	- Se houver sucesso
	 */
	 
	 //----Testes de verificaçõs--------------------------
	 
	 if(descritor == NULL)
	 {
		 printf("		Ooops! O descritor é nulo!\n");
		 return 0;		 
	 }
	 struct nodo *novo;
	 novo = (struct nodo *) malloc(sizeof(struct nodo));
	 if( novo == NULL)
	 {
		 printf("		Ooops! Socorro! Malloc retornou NULL!");
		 return 0;
	 }
	 	 
	 //---------------------------------------------------
	 novo->chave = chave;
	 if( anterior == NULL)
	 {
		 novo->prev = NULL;
		 novo->next = NULL;
		 descritor->head = novo;
		 if( descritor->tail == NULL)
		 {
			 
			 /*
			  * Se não houver nada e nova a estrutura
			  */
			  
			 descritor->tail = novo;
			 descritor->tamanho++;
		 }
		 else
		 {
			 			 
			 /*
			  * Se não houver nada e  não for
			  * nova a estrutura
			  */
			  
			 novo->next->prev = novo;
			 descritor->tamanho++;
		 }
	 }
	 else
	 {
		 novo->next = anterior->next;
		 novo->prev = anterior;
		 anterior->next = novo;
		 if(novo->next == NULL)
		 {
			 
			 /*
			  * Se for inserido no final
			  * do vetor
			  */
			  
			 descritor->tail = novo;
			 descritor->tamanho++;
		 }
		 else
		 {
			 
			 /*
			  * Se for no inserido no meio
			  * do vetor
			  */
			  
			 novo->next->prev = novo;
			 descritor->tamanho++;
		 }
	 }
	 ;
	return 1;
}
struct nodo *get(unsigned int posicao, struct desc_lista *descritor)
{
	
	/*
	 * Entradas:	Posicao 	- Posicao
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		Retorna ponteiro para um nodo da lista de ordem posicao
	 * 
	 * Saída:		descritor	- Do Nodo do posicao
	 * 				NULL		- Em caso de erro
	 */
	 
	struct nodo *temp;
	temp = malloc(sizeof(struct nodo));
	int i;
	if( posicao >= descritor->tamanho)
	{
		return 0;
	}
	else
	{
		temp = descritor->head; 
		for(i = 0; i<= posicao;i++)
		{
			if( i == posicao)
			{
				return temp;
			}
			else
			{
				temp = temp->next;
				if(temp == NULL)
				{
					return temp;
				}
			}
		}
	}
}
int set(struct nodo *ptr, int *x, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Ptr 		- Ponteiro do nodo
	 * 				X			- O valor que deve ser inserido
	 * 				Descritor	- Lista que será trabalha
	 *Ooops! 
	 * Função:		troca conteúdo do elemento apontado por ptr
	 * 
	 * Saída:		0	- Em caso de erro
	 * 				1	- Em caso de sucesso
	 */
	 struct nodo *temp;
	 temp = malloc(sizeof(struct nodo));
	 temp->chave = *x;
	 ptr->chave = temp->chave;

	 if( temp->chave != ptr->chave)
	 {
		 free(temp);
		 return 0;
	 }
	 free(temp);
	return 1;
}
int remov(struct nodo *ptr, struct desc_lista *descritor)
{
	/*
	 * Entradas:	ptr 		- Nodo recebido
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		Remove o prt (NODO) da estrutura
	 * 
	 * Saída:		0 - Se houver um erro
	 * 				1 - Se não houver erro
	 */
	 printf("Ptr %p\n", ptr);
	if(descritor->tail == ptr)
	{
		descritor->tail = ptr->prev;
		ptr->prev->next = NULL;
		ptr->prev->next = NULL;
		descritor->tamanho--;
		return 1;
	}
	else
	{
		ptr->next->prev = ptr->prev;
		if( descritor->head == ptr)
		{
			descritor->head = ptr->next;
			descritor->tamanho--;
			return 1;
		}
		else
		{
			ptr->prev->next = ptr->next;
			descritor->tamanho--;
			return 1;
		}
	}
	return 0;
}
struct nodo *locate(int chave, struct nodo *de)
{	
	/*
	 * Entradas:	Chave 		- Valor de um nodo
	 * 				De			- Nodo do qual começao trabalho
	 *
	 * Função:		Retorna ponteiro para o primeiro elemento
	 * 				com chave procurando a partir da posição 
	 * 				apontada por DE
	 * 
	 * Saída:		Ponteiro	- Valor onde se encontra a chave
	 * 				NULL		- Se não houver o valor
	 */
	 
	 struct nodo *temp;
	 temp = malloc(sizeof(struct nodo));
	 temp = de;
	 for(;;)
	 {
		 if(temp->chave == chave)
		 {
			 if(temp->next != NULL)
			 {
				 temp = temp->next;
				 return temp->prev;
			 }
			 else
			 {
				 if(temp->prev == NULL)
				 {
					 return de;
				 }
				 temp = temp->prev;
				 return temp->next;
			 }
		 }
		 else
		 {
			 temp = temp->next;
			 if(temp == NULL)
			 {
				 return NULL;
			 }
		 }
	 }

}
unsigned int length(struct desc_lista *descritor)
{
	/*
	 * Entradas:	Descritor	- Lista que será trabalho
	 *
	 * Função:		Retorna o comprimento atual da lista
	 * 
	 * Saída:		Comprimento
	 */
	return descritor->tamanho;
}
int print(struct nodo *ptr)
{
	/*
	 * Entradas:	Nodo	- Nodo de trabalho
	 *
	 * Função:		imprime conteúdo do nodo apontado por ptr 
	 * 				(incluindo endereços apontados por proximo
	 * 				e anterior em hexadecimal) 
	 * 
	 * Saída:		0 - Caso tenha um erro
	 * 				1 - Caso não haja erros
	 */
	 
	 if(ptr == NULL)
	 {
		 return 0;
	 }
	 else
	 {
		 printf("		Nodo: %p\n", ptr);
		 printf("		%p Prev<-Nodo \n", ptr->prev);
		 printf("				 %d\n", ptr->chave);
		 printf("	    	   		Nodo->Next %p\n\n", ptr->next);
		 return 1;
	 }
	return 0;
}
