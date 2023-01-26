#include <stdio.h>
#include <stdlib.h>

struct numero{
    int num;
    struct numero *next;
};
typedef struct numero Numero;
////////////////////////////////////////////////////

void inserisci(Numero **tabella, int valore, int a, int b, int n){

    // Calcola indice con funzione hash
    int indice = ((a * valore + b) % 999149) % (2*n);

    Numero *listaPtr = tabella[indice];

    // Ricerca valore già inserito
    while(listaPtr != NULL){

        if(listaPtr->num == valore)
            return;

        listaPtr = listaPtr->next;
    }

    // Allocazione spazio per nuovo elemento
    Numero *nuovo = malloc(sizeof(Numero));
    nuovo->num = valore;

    // Inserimento in testa alla lista
    nuovo->next = tabella[indice];
    tabella[indice] = nuovo;
}

void output(Numero **tabella, int n){

    int conflitti = 0;
    int lunghezza_max = 0;
    int elementi = 0;

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

        elementi += lunghezza;
    }

    printf("%d\n", conflitti);
    printf("%d\n", lunghezza_max);
    printf("%d\n", elementi);
}

void elimina_lista_rec(Numero *lista){

    if(lista != NULL){
        elimina_lista_rec(lista->next);
        free(lista);
    }
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

    // Eliminazione delle liste memorizzate in tabella
    for(int i=0; i<2*n; i++){
        elimina_lista_rec(tabella[i]);
    }
    free(tabella);

    return 0;
}
