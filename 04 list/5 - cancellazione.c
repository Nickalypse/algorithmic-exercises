#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    struct numero *next;
};
typedef struct numero Numero;
typedef Numero *ListaDiNumeri;

///////////////////////////////////////////

void stampa_lista_rec(ListaDiNumeri *listaPtr){

    if(*listaPtr != NULL){
        printf("%d ", (*listaPtr)->n);
        stampa_lista_rec(&(*listaPtr)->next);
    }
    else{
        printf("\n");
    }
}

void filtra_lista(ListaDiNumeri *listaPtr, int media){

    ListaDiNumeri attualePtr = *listaPtr;
    ListaDiNumeri precedentePtr = NULL;

    while(attualePtr != NULL){

        if(attualePtr->n <= media){

            if(precedentePtr == NULL){
                *listaPtr = attualePtr->next;
                free(attualePtr);
                attualePtr = *listaPtr;
            }
            else{
                precedentePtr->next = attualePtr->next;
                free(attualePtr);
                attualePtr = precedentePtr->next;
            }
        }
        else{
            precedentePtr = attualePtr;
            attualePtr = attualePtr->next;
        }
    }
}

void elimina_lista_rec(ListaDiNumeri *listaPtr){

    if(*listaPtr != NULL){
        elimina_lista_rec(&(*listaPtr)->next);
        free(*listaPtr);
    }
}

///////////////////////////////////////////
int main()
{
    ListaDiNumeri listaPtr = NULL, indicePtr;
    int n, valore;
    int media = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &valore);

        // Allocazione spazio per nuovo elemento della lista
        ListaDiNumeri nuovo = malloc(sizeof(Numero));
        nuovo->n = valore;
        nuovo->next = NULL;

        // Inserimento in coda alla lista
        if(listaPtr == NULL){
            listaPtr = nuovo;
            indicePtr = listaPtr;
        }
        else{
            indicePtr->next = nuovo;
            indicePtr = indicePtr->next;
        }

        media += valore;
    }

    media /= n;
    printf("%d\n", media);

    stampa_lista_rec(&listaPtr);

    filtra_lista(&listaPtr, media);
    stampa_lista_rec(&listaPtr);

    elimina_lista_rec(&listaPtr);

    return 0;
}

