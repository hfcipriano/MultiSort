#include "mergesort.h"

extern lista *newLista();

void divide(lista *L, lista *A, lista *B){
	int i = 0, qtd = L->qtd;
	node *n;

	while(i < qtd){
		n = L->raiz;
		L->desconectaNode(L, n);

		if(i < qtd/2)
			A->addNodeFinal(A, n);
		else
			B->addNodeFinal(B, n);
		i++;
	}

}

lista *mergeSort(lista *L){
	int i = 0, qtd = L->qtd;
        node *n;
        lista *A = newLista(), *B = newLista();

	if(qtd > 1)
		divide(L, A, B);
	if(A->qtd > 1)
		mergeSort(A);
	if(B->qtd > 1)
		mergeSort(B);
	merge(L, A, B);
}

void merge(lista *L, lista *A, lista *B){
	node *a = A->raiz, *b = B->raiz;

	while(a != NULL && b != NULL){
		if(a->valor < b->valor){
			A->desconectaNode(A, a);
			L->addNodeFinal(L, a);
			a = A->raiz;
		}
		else{
			B->desconectaNode(B, b);
			B->addNodeFinal(L, b);
			b = B->raiz;
		}
	}
	while(a != NULL){
		A->desconectaNode(A, a);
		L->addNodeFinal(L, a);
		a = A->raiz;
	}
	while(b != NULL){
		B->desconectaNode(B, b);
		L->addNodeFinal(L, b);
		b = B->raiz;
	}
}
