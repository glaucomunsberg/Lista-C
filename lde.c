#include "lde.h"
#include <stdio.h>

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
	return 0;
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

}
int set(struct nodo *ptr, int *x, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Ptr 		- Ponteiro do nodo
	 * 				X			- O valor que deve ser inserido
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		troca conteúdo do elemento apontado por ptr
	 * 
	 * Saída:		0	- Em caso de erro
	 * 				1	- Em caso de sucesso
	 */
	 
	return 0;
}
int delete(struct nodo *ptr, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Ptr 		- Ponteiro do nodo
	 * 				Descritor	- Lista que será trabalha
	 *
	 * Função:		Apaga elemento apontado por ptr
	 * 
	 * Saída:		0	- Em caso de erro
	 * 				1	- Em caso de sucesso
	 */
	 
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
	 
	return 0;
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
	 
	return 0;
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

