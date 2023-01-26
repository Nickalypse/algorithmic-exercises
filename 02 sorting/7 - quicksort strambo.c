#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int pre_distribuzione(int a[], int tot){

    int app;
    int i = -1;

    for(int j=0; j<tot; j++){

        if(a[j] % 2 == 0){
            i++;
            app = a[i];
            a[i] = a[j];
            a[j] = app;
        }
    }

    return (i+1);
}

int distribuzione(int a[], int sx, int px, int dx) {

    int app, x, i;

    // scambia pivot con ultimo elemento
    app = a[px];
    a[px] = a[dx];
    a[dx] = app;

    x = a[dx];
    i = sx - 1;

    for(int j=sx; j<dx; j++){

        if(a[j] <= x){
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

void quicksort( int a[], int sx, int dx ) {

  int perno, pivot;

  if( sx < dx ) {

    /* sceglie una posizione a caso tra sx e dx inclusi. */
    pivot = /*rand() % (dx-sx+1) + sx*/ dx;

    /* separa gli elementi minori di a[pivot] da quelli maggiori o uguali */
    perno = distribuzione(a, sx, pivot, dx);

    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
  }
}

/* Lettura di un array di interi da input.
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ )
	  scanf("%d", (*a)+i);

  return 0;
}


int main() {

  int *A;
  int n, pre;

  if(legge(&A, &n)) return 1;

  pre = pre_distribuzione(A, n);

  srand(time(NULL));
  quicksort(A, 0, pre-1);
  quicksort(A, pre, n-1);

  /* Stampa l'array ordinato */
  for( int i = 0; i < n; i++ )
    printf("%d ", A[i]);

  return 0;
}

