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

void rec(ListaDiNumeri *listaPtr){

    static int somma = 0;
    static int somma2 = 0;

    if(*listaPtr != NULL){
        rec(&(*listaPtr)->next);
        somma2 += (*listaPtr)->n;
        (*listaPtr)->n = somma;
        somma = somma2;
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
    }

    stampa_lista_rec(&listaPtr);

    rec(&listaPtr);
    stampa_lista_rec(&listaPtr);

    elimina_lista_rec(&listaPtr);

    return 0;
}

