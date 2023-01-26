#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100


int distribuzione(char *a[], int sx, int px, int dx) {

    char *app, *x;
    int i;

    // scambia pivot con ultimo elemento
    app = a[px];
    a[px] = a[dx];
    a[dx] = app;

    x = a[dx];
    i = sx - 1;

    for(int j=sx; j<dx; j++){

        if(strcmp(a[j], x) <= 0){
            i++;
            app = a[i];
            a[i] = a[j];
            a[j] = app;
        }
    }

    app = a[i+1];
    a[i+1] = a[dx];
    a[dx] = app;

    return (i+1);
}


void quicksort( char *a[], int sx, int dx ) {

  int perno, pivot;

  if( sx < dx ) {

    /* sceglie una posizione a caso tra sx e dx inclusi. */
    pivot = rand() % (dx-sx+1) + sx;

    /* separa gli elementi minori di a[pivot] da quelli maggiori o uguali */
    perno = distribuzione(a, sx, pivot, dx);

    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
  }
}


int main() {

    char **A, parola[SIZE];
    int i, n;

    // Acquisizione dimensione array
    scanf("%d", &n);
    if(n <= 0) return 1;

    // Allocazione dinamica array
    A = malloc(sizeof(char *) * n);
    if(A == NULL) return 1;

    // Acquisizione parole in array
    for( i = 0; i < n; i++ ){
        scanf("%s", parola);
        A[i] = malloc(sizeof(char) * (strlen(parola)+1));
        strcpy(A[i], parola);
    }

    srand(time(NULL));
    quicksort(A, 0, n-1);

    // Stampa l'array ordinato
    for( i = 0; i < n; i++ ){
        printf("%s\n", A[i]);
        free(A[i]);
    }

    free(A);

    return 0;
}

