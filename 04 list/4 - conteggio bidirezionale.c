#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    int ricerche;
    struct numero *next;
    struct numero *prec;
};

typedef struct numero Numero;
typedef Numero *ListaDiNumeri;
///////////////////////////////////////////////////////

int ricerca(ListaDiNumeri *listaPtr, int x){

    ListaDiNumeri indicePtr = *listaPtr;
    int i=0;

    while(indicePtr != NULL){

        if(indicePtr->n == x){

            (indicePtr->ricerche) += 1;

            ListaDiNumeri maggiorePtr = indicePtr->prec;

            while(maggiorePtr != NULL && maggiorePtr->ricerche < indicePtr->ricerche){
                maggiorePtr = maggiorePtr->prec;
            }

            if(maggiorePtr != indicePtr->prec){

                // scollego indicePtr da lista bidirezionale
                indicePtr->prec->next = indicePtr->next;
                if(indicePtr->next != NULL){
                    indicePtr->next->prec = indicePtr->prec;
                }

                if(maggiorePtr == NULL){
                    indicePtr->prec = NULL;
                    indicePtr->next = *listaPtr;
                    (*listaPtr)->prec = indicePtr;
                    *listaPtr = indicePtr;
                }
                else{
                    maggiorePtr->next->prec = indicePtr;
                    indicePtr->next = maggiorePtr->next;
                    indicePtr->prec = maggiorePtr;
                    maggiorePtr->next = indicePtr;
                }
            }

            return i;
        }

        indicePtr = indicePtr->next;
        i++;
    }

    return -1;
}

void stampa(ListaDiNumeri *listaPtr){

    if(*listaPtr != NULL){
        //printf("[%d|%d]  ", (*listaPtr)->n, (*listaPtr)->ricerche);
        stampa(&(*listaPtr)->next);
        free(*listaPtr);
    }
}

///////////////////////////////////////////////////////
int main()
{
    ListaDiNumeri listaPtr = NULL;
    ListaDiNumeri indicePtr = NULL;
    ListaDiNumeri nuovo;

    int tot, x, ris;

    scanf("%d", &tot);

    // Ciclo per acquisizione lista in ordine di inserimento
    for(int i=0; i<tot; i++){

        nuovo = malloc(sizeof(Numero));
        nuovo->ricerche = 0;
        nuovo->next = NULL;
        nuovo->prec = indicePtr;
        scanf("%d", &(nuovo->n));

        if(listaPtr == NULL){
            listaPtr = nuovo;
            indicePtr = listaPtr;
        }
        else{
            indicePtr->next = nuovo;
            indicePtr = indicePtr->next;
        }
    }

    while(1){

        scanf("%d", &x);

        ris = ricerca(&listaPtr, x);
        printf("%d\n", ris);

        if(ris == -1)
            break;
    }

    stampa(&listaPtr);

    return 0;
}

