#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void distribuzione(int a[], int sx, int px, int dx, int *perno1, int *perno2) {

    int app, x, i, k;

    // scambia pivot con ultimo elemento
    app = a[px];
    a[px] = a[dx];
    a[dx] = app;

    x = a[dx];
    i = sx - 1;
    k = sx - 1;

    for(int j=sx; j<(dx+1); j++){

        if(a[j] < x){
            i++;
            app = a[i];
            a[i] = a[j];
            a[j] = app;
        }

        if(a[j] == x){

            if(k == (sx-1)){
                k = i+1;
            }
            else{
                k++;
            }
            app = a[k];
            a[k] = a[j];
            a[j] = app;
        }
    }
    /*
    for(i=sx; i<dx+1; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n");
    */
    *perno1 = i;
    *perno2 = k+1;
}

void quicksort( int a[], int sx, int dx ) {

  int pivot, perno1, perno2;

  if( sx < dx ) {

    /* sceglie una posizione a caso tra sx e dx inclusi. */
    pivot = /*rand() % (dx-sx+1) + sx*/ dx;

    /* separa gli elementi minori di a[pivot] da quelli maggiori o uguali */
    distribuzione(a, sx, pivot, dx, &perno1, &perno2);

    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno1);
    quicksort(a, perno2, dx);
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

  int i, n, *A;

  if(legge(&A, &n)) return 1;

  srand(time(NULL));
  quicksort(A, 0, n-1);

  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ )
    printf("%d ", A[i]);

  return 0;
}
