#include <stdio.h>
#include <stdlib.h>

struct numero{
    int n;
    struct numero *destra;
    struct numero *centro;
    struct numero *sinistra;
};
typedef struct numero Numero;
typedef Numero *Albero;
/////////////////////////////////////////////////

void inserisci_in_albero(Albero *alberoPtr, int valore){

    Albero nuovo = malloc(sizeof(Numero));
    nuovo->n = valore;
    nuovo->destra = NULL;
    nuovo->centro = NULL;
    nuovo->sinistra = NULL;

    if(*alberoPtr == NULL){
        *alberoPtr = nuovo;
        return;
    }

    Albero padrePtr = NULL;
    Albero indicePtr = *alberoPtr;

    while(indicePtr != NULL){

        padrePtr = indicePtr;

        if(valore < indicePtr->n)
            indicePtr = indicePtr->sinistra;
        else if(valore % indicePtr->n == 0)
            indicePtr = indicePtr->centro;
        else
            indicePtr = indicePtr->destra;
    }

    if(valore < padrePtr->n)
        padrePtr->sinistra = nuovo;
    else if(valore % padrePtr->n == 0)
        padrePtr->centro = nuovo;
    else
        padrePtr->destra = nuovo;
}

int nodi_con_tre_figli(Albero *a){

    if(*a != NULL){

        if((*a)->sinistra != NULL && (*a)->centro != NULL && (*a)->destra != NULL){
            return  1 +
                    nodi_con_tre_figli(&(*a)->sinistra) +
                    nodi_con_tre_figli(&(*a)->centro) +
                    nodi_con_tre_figli(&(*a)->destra);
        }
        else{
            return  nodi_con_tre_figli(&(*a)->sinistra) +
                    nodi_con_tre_figli(&(*a)->centro) +
                    nodi_con_tre_figli(&(*a)->destra);
        }
    }
    else
        return 0;
}

void elimina_albero(Albero *alberoPtr){

    if(*alberoPtr != NULL){
        elimina_albero(&(*alberoPtr)->destra);
        elimina_albero(&(*alberoPtr)->centro);
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

    printf("%d\n", nodi_con_tre_figli(&alberoPtr));

    elimina_albero(&alberoPtr);

    return 0;
}
