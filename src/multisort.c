#include "../inc/bibliotecas.h"
#include "../inc/structs.h"
#include <time.h>

extern lista *newLista();
extern node *newNode(int);
extern void quickSort(lista*);
extern void mergeSort(lista*);
extern lista* insertionSort(lista*);
extern void selectionSort(lista*);
int cont;
int main(int argc, char **argv){
        if(argc<5){
		printf("\nSintaxe:\nmultisort <Metodo de ordenacao> <Tipo de saida> <Arquivo> <quantidade de numeros>\n\n");
		printf("Metodo de ordenacao: -q , -m, -i ou -s\n");
		printf("q: quicksort, m: mergesort, i: insertionsort, m: mergesort\n\n");
		printf("Tipo de saida: -t ou -b\n");
		printf("t: texto, b: binario\n\n");
                return -1;
        }else{
                int i,*v,n = atoi(argv[4]);
                char *filename = argv[3], *metodo = argv[1], *saida = argv[2];
                FILE *arq;
		lista *l = newLista();
		cont = 0;
		//Lendo inteiros do arquivo para um vetor e gerando uma lista
                v = (int*) malloc(n*sizeof(int));
                arq = fopen(filename,"rb+");
                fread(v,sizeof(int),n,arq);
                for(i=0; i<n; i++){
			l->addNodeFinal(l, newNode(v[i]));
                }
                free(v);
                fclose(arq);
		clock_t inicio, fim;
		//printListaTexto(l);
		//printf("\n\n");
		inicio = clock();
		switch(metodo[1]){
			case 'q': quickSort(l);
				  break;
			case 'm': mergeSort(l);
				  break;
			case 'i': insertionSort(l);
				  break;
			case 's': selectionSort(l);
				  break;
			default: printf("Metodo invalido\n");
		}
		fim = clock();
		//printf("\nDuracao: %lf\n", ((double)(fim - inicio)/CLOCKS_PER_SEC));
		if(saida[1] == 't'){
			l->printListaTexto(l);
		}else{
			l->printListaBin(l,n);
		}
                return 0;
        }
}

