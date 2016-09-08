#include "quicksort.h"

extern lista *newLista();
extern node *newNode(int);
extern int cont;
void partition(lista *L, lista *A, lista *B, lista *C){
	node *n;
	int pivot, cont2 = 0;
	cont++;
	if(L->raiz != NULL){
        n = L->raiz;
		pivot = n->valor;
		while(n != NULL){
			cont2++;
			L->desconectaNode(L, n);
			if(n->valor < pivot){
				A->addNodeFinal(A, n);
				//A->printListaTexto(A);
			}
			if(n->valor == pivot){
				B->addNodeFinal(B, n);
				//B->printListaTexto(B);
			}
			if(n->valor > pivot){
				C->addNodeFinal(C, n);
				//C->printListaTexto(C);
			}
       		n = L->raiz;
		}
	}
	//printf("\nCONT2: %d\n", cont2);
}

void quickSort(lista* L){
	node *l = L->raiz;
	lista *A = newLista(), *B = newLista(), *C = newLista();
	if(l != NULL){
		partition(L, A, B, C);
        quickSort(A);
        quickSort(C);
        L->raiz = A->raiz;
        L->folha = A->folha;
        if(B->raiz != NULL){
            if(L->folha == NULL){
                L->raiz = B->raiz;
            }else{
                L->folha->proximo = B->raiz;
                B->raiz->anterior = L->folha;
            }
            L->folha = B->folha;
        }
        if(C->raiz != NULL){
            if(L->folha == NULL){
                L->raiz = C->raiz;
            }else{
                L->folha->proximo = C->raiz;
                C->raiz->anterior = L->folha;
            }
            L->folha = C->folha;
        }
	}
}
