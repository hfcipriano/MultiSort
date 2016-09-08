#include "insertionsort.h"

lista *insertionSort(lista *l){

    node *aux, *anterior, *inverse;
    aux = l->raiz;
    int auxValor=l->qtd;

        if(l->verificar( l) == 1) //Verifica se a lista contem 2 ou mais elementos
        {

            while(aux->proximo!=NULL)
            {
                inverse=aux->proximo;
                  if(aux->valor > inverse->valor)
                  {

                    aux=l->swap(l,aux,inverse);
                    aux=aux->proximo;
                    anterior=aux->anterior;


                        while((anterior->anterior!=NULL)&&(anterior->valor < anterior->anterior->valor))

                        {
                            anterior=l->swap(l,anterior->anterior,anterior);
                        }

                  }
                  else
                    aux=aux->proximo;
            }


	return l;
    }
}
