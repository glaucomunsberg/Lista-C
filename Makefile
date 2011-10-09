############################# Makefile ##########################
LAS = las.o lastest.o
ListaSeq: $(LAS)
	gcc $(LAS) -o ListaSeq

lastest.o: las.h lastest.c
	gcc -c lastest.c

las.o: las.h las.c
	gcc -c las.c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf $(LAS)

