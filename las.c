#include "las.h"
#include <stdio.h>

int insert(unsigned int posicao, int chave, struct desc_lista *descritor)
{
	/*
	 * Entradas:
	 * 				Posicao		- Contem a posicao em que deve ser inserido
	 * 				Chave		- Valor que deve ser inserido
	 * 				Descritor	- A estrutura por um ponteiro
	 *
	 * Função:		
	 * 				Insere o valor CHAVE na posição POSICAO  dentro da estrutura
	 * 
	 * Saída:
	 * 				0	- Se houver erro
	 * 				1	- Se não houver erro
	 */
	 
	int i;
	if(descritor->position >= MAX)
	{
		printf("\n		Ooops! Lista cheia\n");
		return 0;
	}
	else
	{
		if(posicao > descritor->position || posicao < 0 )
		{
			printf("\n		Ooops! Posição Inexistente\n");
			return 0;
		}
		else
		{
			if( descritor->position != 0)
			{
				for(i= descritor->position; i > posicao; i--)
				{
					descritor->vet[i] = descritor->vet[i-1];
				}
			}
			descritor->position++;
			descritor->vet[posicao] = chave;
			return 1;
		}
	}
}
int *get(unsigned int posicao, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Posicao		- Contem a posicao em que deve ser inserido
	 * 				Descritor	- A estrutura por um ponteiro
	 *
	 * Função:		Retorna o valor da posição POSICAO da estrutura
	 * 
	 * Saída:		NULL		- Caso ocorra um erro
	 * 				Ponteiro	- Caso tenha sucesso
	 */
	 
	if(posicao >= descritor->position || posicao < 0)
	{
		return NULL;
	}
	else
	{
		return &descritor->vet[posicao];
	}
}
int set(int posicao, int x, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Posicao		- Contem a posicao em que deve ser inserido
	 * 				x			- Valor
	 * 				Descritor	- A estrutura por um ponteiro
	 *
	 * Função:		Insere o valor X na posição POSICAO na estrutura
	 * 
	 * Saída:		0	- Caso ocorra um erro
	 * 				1 	- Caso tenha sucesso
	 */
	 
	if(posicao >= descritor->position || posicao < 0)
	{
		return 0;
	}
	else
	{
		descritor->vet[posicao] = x;
		return 1;
	}
	
}
int delete(int posicao, struct desc_lista *descritor)
{
	/*
	 * Entradas:	Posicao		- Contem a posicao em que deve ser inserido
	 * 				Descritor	- A estrutura por um ponteiro
	 *
	 * Função:		Deleta o valor daquela posição
	 * 
	 * Saída:		0	- Caso ocorra um erro
	 * 				1	- Caso tenha sucesso
	 */
	 
	int i;
	if( descritor->position <= posicao )
	{
		return 0;
	}
	else
	{
		for(i= posicao; i<descritor->position; i++)
		{
			descritor->vet[i] = descritor->vet[i+1];
		}
		descritor->position--;
		return 1;
	}
}
int *locate(int chave, struct desc_lista *descritor)
{
	/*
	 * Entradas:	chave		- Contendo o valor que se procura
	 * 				Descritor	- A estrutura por um ponteiro
	 *
	 * Função:		Procura o primeiro valor igual a CHAVE e retorna
	 * 					o seu através de um ponteiro;
	 * 
	 * Saída:		NULL		- Caso ocorra um erro
	 * 				Ponteiro	- Caso tenha sucesso
	 */
	 
	int i;
	int j;
	i=0;
	
	while( i < descritor->position)
	{
		if( descritor->vet[i] == chave)
		{
			return &descritor->vet[i];
			i = MAX+1;
		}
		i++;
	}
	return NULL;
}
unsigned int length(struct desc_lista *descritor)
{
	/*
	 * Entradas:	Descritor	- A estrutura por um ponteiro
	 *
	 * Função:		Retorna o comprimento da lista
	 * 
	 * Saída:		Retorna o comprimento da lista
	 */
	 
	return descritor->position;
}

	
