#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    struct numero *next;
    struct numero *prec;
};

typedef struct numero Numero;
typedef Numero *ListaDiNumeri;

//////////////////////////////////////////////////
int main()
{
    ListaDiNumeri listaPtr = NULL;
    ListaDiNumeri indicePtr = NULL;
    ListaDiNumeri nuovo;

    int tot;

    scanf("%d", &tot);

    // Ciclo per acquisizione lista in ordine di inserimento
    for(int i=0; i<tot; i++){

        nuovo = malloc(sizeof(Numero));
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

    while(indicePtr != NULL){
        printf("%d\n", indicePtr->n);
        indicePtr = indicePtr->prec;
        if(indicePtr != NULL)
            free(indicePtr->next);
    }

    return 0;
}

