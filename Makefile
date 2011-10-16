############################# Makefile ##########################
all: ListaSeq ListaDup
LAS = las.o lastest.o
#Lista Sequencial################################################
ListaSeq: $(LAS)
	gcc -g $(LAS) -o ListaSeq

lastest.o: las.h lastest.c
	gcc -c lastest.c

las.o: las.h las.c
	gcc -c las.c
	
#Lista Duplamente encadeada######################################
LDE = lde.o	ldetest.o
ListaDup:$(LDE)
	gcc -g $(LDE) -o ListaDup
	
ldetest.o: lde.h ldetest.c
	gcc -c ldetest.c

lde.o: lde.h lde.c
	gcc -c lde.c
clean:
	rm LastTest*.o
mrproper: clean
	rm -rf $(LAS)

