#ifndef LDE_H 
#define LDE_H
#define MAX 10
struct desc_lista * init();
int insert(struct nodo * anterior, int chave, struct desc_lista * descritor);
struct nodo * get(unsigned int posicao, struct desc_lista * descritor);
int set(struct nodo * ptr, int * x, struct desc_lista * descritor);
int delete(struct nodo * ptr, struct desc_lista * descritor);
struct nodo * locate(int chave, struct nodo * de);
unsigned int length(struct desc_lista * descritor);
int print(struct nodo * ptr);
#endif
