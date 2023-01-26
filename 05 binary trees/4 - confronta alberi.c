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

void confronta(Albero *albero1, Albero *albero2, int k){

    Albero indice1 = *albero1;
    Albero indice2 = *albero2;

    while(indice1 != NULL && indice2 != NULL){

        if(indice1->n != indice2->n)
            break;

        if(indice1->n == k && indice2->n == k){
            printf("1\n");
            return;
        }

        if(k > indice1->n)
            indice1 = indice1->destra;
        else
            indice1 = indice1->sinistra;

        if(k > indice2->n)
            indice2 = indice2->destra;
        else
            indice2 = indice2->sinistra;
    }

    printf("0\n");
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
    Albero albero1 = NULL;
    Albero albero2 = NULL;
    int n, k, valore;

    scanf("%d %d", &n, &k);

    // Inserimento valori nel primo albero
    for(int i=0; i<n; i++){
        scanf("%d", &valore);
        inserisci_in_albero(&albero1, valore);
    }

    // Inserimento valori nel secondo albero
    for(int i=0; i<n; i++){
        scanf("%d", &valore);
        inserisci_in_albero(&albero2, valore);
    }

    confronta(&albero1, &albero2, k);

    elimina_albero(&albero1);
    elimina_albero(&albero2);

    return 0;
}
