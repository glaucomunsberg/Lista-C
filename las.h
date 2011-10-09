#ifndef LAS_H 
#define LAS_H
#define MAX 10
typedef struct desc_lista{
	int vet[MAX];
	int position;
}desc_lista;

int insert(unsigned int posicao, int chave, struct desc_lista *descritor);
int * get(unsigned int posicao, struct desc_lista *descritor);
int set(int posicao, int x, struct desc_lista *descritor);
int delete(int posicao, struct desc_lista *descritor);
int * locate(int chave, struct desc_lista *descritor);
unsigned int length(struct desc_lista *descritor);
#endif
