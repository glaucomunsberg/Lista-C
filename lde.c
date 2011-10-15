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
		 printf("Ooops! O descritor é nulo!\n");
		 return 0;		 
	 }
	 struct nodo *novo;
	 novo = (struct nodo *) malloc(sizeof(struct nodo));
	 if( novo == NULL)
	 {
		 printf("Ooops! Socorro! Malloc retornou NULL!");
		 return 0;
	 }
	 	 
	 //---------------------------------------------------
	 novo->chave = chave;
	 if( anterior == NULL)
	 {
		 printf("ANTERIOR é NULO!n");
		 //Se não houver nada na estrutura
		 novo->prev = NULL;
		 novo->next = NULL;
		 descritor->head = novo;
		 if( descritor->tail == NULL)
		 {
			 printf("Noa tem nada e não é novo!\n");
			 //Se não houver nada e não for nova a estrutura
			 descritor->tail = novo;
		 }
		 else
		 {
			 novo->next->prev = novo;
		 }
	 }
	 else
	 {
		 novo->next = anterior->next;
		 novo->prev = anterior;
		 anterior->next = novo;
		 if(novo->next == NULL)
		 {
			 //Se for no fim
			 printf("esta no fim");
			 descritor->tail = novo;
		 }
		 else
		 {
			 //Se for no meio
			 printf("esta no meio!");
			 novo->next->prev = novo;
		 }
	 }
	 descritor->tamanho++;
	 printf("TESTE: Descritor->Head %p\n Descritor->Tail %p\n Descritor->Tamanho %d\n", descritor->head, descritor->tail, descritor->tamanho);
	return 1;
}
struct nodo *get(unsigned int posicao, struct desc_lista *descritor)
{
	
	/*
	 * Entradas:	Posicao 	- Ponteiro do elemento anterior
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		Retorna ponteiro para um nodo da lista de ordem posicao
	 * 
	 * Saída:		descritor	- Do Nodo do posicao
	 * 				NULL		- Em caso de erro
	 */
	struct nodo *p;
	if(descritor->head == NULL)
	{
		printf("não tem nada");
		return NULL;
	}
	return p;
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
	 
	return 0;
}
int delete(struct nodo *ptr, struct desc_lista *descritor)
{
	if(descritor->tail == ptr)
	{
		descritor->tail = ptr->prev;
	}
	else
	{
		ptr->next->prev = ptr->prev;
		if( descritor->head = ptr)
		{
			descritor->head = ptr->next;
		}
		else
		{
			ptr->prev->next = ptr->next;
		}
	}
	return 0;
}
struct nodo *locate(int chave, struct nodo *de)
{	
	/*
	 * Entradas:	Chave 		- Valor de um nodo
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		Retorna ponteiro para o primeiro elemento
	 * 				com chave procurando a partir da posição 
	 * 				apontada por DE
	 * 
	 * Saída:		Ponteiro	- Valor onde se encontra a chave
	 * 				NULL		- Se não houver o valor
	 */

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
	 printf("AQUUUUI!\n");
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
	 
	return 0;
}
