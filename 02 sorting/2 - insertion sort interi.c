#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int v[], int size);

int main()
{
    int *v;
    int size;

    scanf("%d", &size);
    v = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        scanf("%d", &v[i]);
    }

    insertion_sort(v, size);

    for(int i=0; i<size; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}

void insertion_sort(int v[], int size){

    int value, j;

    for(int i=1; i<size; i++){

        value = v[i];
        j = i-1;

        while((j >= 0) && (v[j] > value)){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = value;
    }
}

