#include "mergesort.h"

extern lista *newLista();
extern void addNodeFinal(lista*, node*);
extern void rmNodeInicio(lista*);
extern void printListaTexto(lista*);

void mergeSort(lista *L){

	int i = 0, cont = L->qtd;
	node *n;
	lista *A = newLista(), *B = newLista();
	if(L->qtd > 0){
		while(i < cont){
			n = L->raiz;
			rmNodeInicio(L);

			if(i < cont/2){
			printf("\nCONT %d", cont/2);
				addNodeFinal(A, n);}
			else
				addNodeFinal(B, n);
			i++;
		}
	}
		if(A->raiz != NULL)
			mergeSort(A);

			merge(L, A, B);
		//if(B->raiz != NULL)
			//mergeSort(B);
}

void merge(lista *L, lista *A, lista *B){

	node *a = A->raiz, *b = B->raiz;
	int cont, i = 0;

	if(a != NULL && b != NULL){

		cont = A->qtd + B->qtd;

		while(i < cont){
			if(a->valor < b->valor){
				rmNodeInicio(A);
				addNodeFinal(L, a);
				a = A->raiz;
			}
			else if(a->valor >= b->valor){
                                rmNodeInicio(B);
                                addNodeFinal(L, a);
                                b = B->raiz;
                        }
			i++;
		}
	}

}

