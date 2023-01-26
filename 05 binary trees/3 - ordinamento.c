#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    struct numero *destra;
    struct numero *sinistra;
};
typedef struct numero Numero;
typedef Numero *Albero;
/////////////////////////////////////////////////

void inserisci_in_albero(Albero *alberoPtr, int valore){

    Albero nuovo = malloc(sizeof(Numero));
    nuovo->n = valore;
    nuovo->destra = NULL;
    nuovo->sinistra = NULL;

    if(*alberoPtr == NULL){
        *alberoPtr = nuovo;
        return;
    }

    Albero padrePtr = NULL;
    Albero indicePtr = *alberoPtr;

    while(indicePtr != NULL){

        padrePtr = indicePtr;

        if(valore > indicePtr->n)
            indicePtr = indicePtr->destra;
        else
            indicePtr = indicePtr->sinistra;
    }

    if(valore > padrePtr->n)
        padrePtr->destra = nuovo;
    else
        padrePtr->sinistra = nuovo;
}

void visita(Albero *alberoPtr){

    if(*alberoPtr != NULL){

        visita(&(*alberoPtr)->sinistra);
        printf("%d\n", (*alberoPtr)->n);
        visita(&(*alberoPtr)->destra);
    }
}

void elimina_albero(Albero *alberoPtr){

    if(*alberoPtr != NULL){
        elimina_albero(&(*alberoPtr)->destra);
        elimina_albero(&(*alberoPtr)->sinistra);
        free(*alberoPtr);
    }
}

/////////////////////////////////////////////////
int main()
{
    Albero alberoPtr = NULL;
    int n, valore;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &valore);
        inserisci_in_albero(&alberoPtr, valore);
    }

    visita(&alberoPtr);

    elimina_albero(&alberoPtr);

    return 0;
}
