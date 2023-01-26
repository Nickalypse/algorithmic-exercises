#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    struct numero *next;
};

typedef struct numero Numero;
typedef Numero *ListaDiNumeri;
//////////////////////////////////////////////////

int move(ListaDiNumeri *listaPtr, int x){

    ListaDiNumeri attualePtr = *listaPtr;
    ListaDiNumeri precedentePtr = NULL;
    int i=0;

    while(attualePtr != NULL){

        if(attualePtr->n == x){

            if(precedentePtr != NULL){
                precedentePtr->next = attualePtr->next;
                attualePtr->next = *listaPtr;
                *listaPtr = attualePtr;
            }

            return i;
        }

        precedentePtr = attualePtr;
        attualePtr = attualePtr->next;
        i++;
    }

    return -1;
}

void elimina_lista(ListaDiNumeri *listaPtr){

    if(*listaPtr != NULL){
        elimina_lista(&(*listaPtr)->next);
        free(*listaPtr);
    }
}

//////////////////////////////////////////////////
int main()
{
    ListaDiNumeri listaPtr = NULL;
    ListaDiNumeri indicePtr;
    ListaDiNumeri nuovo;

    int tot, x, ris;

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

    while(1){

        scanf("%d", &x);

        ris = move(&listaPtr, x);
        printf("%d\n", ris);

        if(ris == -1)
            break;
    }

    elimina_lista(&listaPtr);

    return 0;
}

