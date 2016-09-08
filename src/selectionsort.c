#include "selectionsort.h"


node *achaMenor(lista *l, node * aux)
{
    node *i, *j;
    int min;
    i = j = aux;
    min = aux->valor;


    while(i != NULL)
    {

        if(i->valor < min)
        {
            j=i;
            min = i->valor;

        }
        i = i->proximo;

}
   return j;
}



node* troca(lista*l,node*a,node*b)
{
    node *auxaa,*auxap,*auxba,*auxbp;

    auxaa=a->anterior;
    auxap=a->proximo;
    auxba=b->anterior;
    auxbp=b->proximo;


   if(auxap == b)
    {
     b=l->swap(l,a,b);
     return b;
    }

    else{
    if(auxaa != NULL)
    {
        auxaa->proximo=b;
        b->anterior=auxaa;


    }else
    {
        l->raiz=b;
    }

    if(auxbp != NULL)
    {
        a->proximo=auxbp;
        auxbp->anterior=a;

    }
    else
    {
        a->proximo=NULL;
	l->folha=a;
    }

    a->anterior=auxba;
    auxba->proximo=a;
    b->proximo=auxap;
    auxap->anterior=b;

    }
            /*Teste
            b->proximo=auxap;
            b->anterior=auxaa;
            a->anterior=auxba;
            a->proximo=auxbp;
            printf("\na:%d",a->valor);
            printf("\nb:%d",b->valor);
            printf("\na anterio:%d",a->anterior->valor);
            printf("\na prox:%d",a->proximo->valor);
            printf("\nb antes:%d",b->anterior->valor);
            printf("\nb prox:%d",b->proximo->valor);

            printf("\nAA:%d",auxap->anterior->valor);
            printf("\nAP:%d",auxaa->proximo->valor);
            printf("\nBP:%d",auxbp->anterior->valor);
            printf("\nBA:%d",auxba->proximo->valor);
            printListaTexto(l);*/



    return b;
}


lista* selectionSort(lista* l)
{
    node *aux,*min,*n;
    aux = l->raiz;
    if(l->verificar(l) == 1)
    {
        while(aux->proximo != NULL)
        {

            min=achaMenor(l, aux);
            aux=troca(l,aux,min);
            aux = aux->proximo;
        }
        return l;
    }
}
