#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    struct numero *next;
};

typedef struct numero Numero;
typedef Numero *ListaDiNumeri;
//////////////////////////////////////////////////

void stampa_lista_rec(ListaDiNumeri *listaPtr){

    if(*listaPtr != NULL){
        stampa_lista_rec(&(*listaPtr)->next);
        printf("%d\n", (*listaPtr)->n);
        free(*listaPtr);
    }
}

//////////////////////////////////////////////////
int main()
{
    ListaDiNumeri listaPtr = NULL;
    ListaDiNumeri indicePtr;
    ListaDiNumeri nuovo;

    int tot;

    scanf("%d", &tot);

    // Ciclo per acquisizione lista in ordine di inserimento
    for(int i=0; i<tot; i++){

        nuovo = malloc(sizeof(Numero));
        nuovo->next = NULL;
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

    stampa_lista_rec(&listaPtr);

    return 0;
}

