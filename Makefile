all:	node lista multisort quicksort mergesort insertionsort selectionsort tool
	@gcc -o bin/multisort multisort.o quicksort.o mergesort.o insertionsort.o selectionsort.o lista.o node.o
	@rm *.o
	@clear
	@echo "Compilado com sucesso!"

node:	inc/bibliotecas.h src/node.h src/node.c
	@gcc -c src/node.c

lista:	node src/lista.h src/lista.c
	@gcc -c src/lista.c

multisort: lista src/multisort.c
	@gcc -c src/multisort.c

quicksort: lista src/quicksort.h src/quicksort.c
	@gcc -c src/quicksort.c


mergesort: lista src/mergesort.h src/mergesort.c
	@gcc -c src/mergesort.c

insertionsort: lista src/insertionsort.h src/insertionsort.c
	@gcc -c src/insertionsort.c

selectionsort: lista src/selectionsort.h src/selectionsort.c
	@gcc -c src/selectionsort.c

tool: tools/leBin.c tools/escreveBin.c
	@gcc -o bin/leBin tools/leBin.c
	@gcc -o bin/escreveBin tools/escreveBin.c

clean:	
	rm -f *.swp *~ *.o bin/* 

release: clean
	cd .. && tar -czf MultiSort.tar.gz MultiSort


