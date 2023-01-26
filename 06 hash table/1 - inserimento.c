#include <stdio.h>
#include <stdlib.h>

struct numero{
    int num;
    struct numero *next;
};
typedef struct numero Numero;
////////////////////////////////////////////////////

void inserisci(Numero **tabella, int valore, int a, int b, int n){

    Numero *nuovo = malloc(sizeof(Numero));
    nuovo->num = valore;

    // Calcola indice con funzione hash
    int indice = ((a * valore + b) % 999149) % (2*n);

    // Inserimento in testa alla lista
    nuovo->next = tabella[indice];
    tabella[indice] = nuovo;
}

void output(Numero **tabella, int n){

    int lunghezza_max = 0;
    int conflitti = 0;

    for(int i=0; i<2*n; i++){

        Numero *indicePtr = tabella[i];
        int lunghezza = 0;


        while(indicePtr != NULL){
            lunghezza++;
            indicePtr = indicePtr->next;
        }

        if(lunghezza > lunghezza_max)
            lunghezza_max = lunghezza;

        if(lunghezza != 0)
            conflitti += (lunghezza - 1);
    }

    printf("%d\n", lunghezza_max);
    printf("%d\n", conflitti);
}

////////////////////////////////////////////////////
int main()
{
    int n, a, b, valore;

    Numero **tabella;

    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);

    // Allocazione dimanica tabella hash (array di puntatori a liste)
    tabella = (Numero **) malloc(sizeof(Numero *) * 2 * n);

    // Inizializzazione tabella hash vuota
    for(int i=0; i<(2*n); i++)
        tabella[i] = NULL;

    for(int i=0; i<n; i++){
        scanf("%d", &valore);
        // Inserimento valore in tabella hash
        inserisci(tabella, valore, a, b, n);
    }

    output(tabella, n);

    return 0;
}
