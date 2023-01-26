#include <stdio.h>
#include <stdlib.h>

void selection_sort(int v[], int size);

int main()
{
    int *v;
    int size;

    scanf("%d", &size);
    v = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        scanf("%d", &v[i]);
    }

    selection_sort(v, size);

    for(int i=0; i<size; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}

void selection_sort(int v[], int size){

    int posMin, temp;

    for(int i=0; i<size-1; i++){

        posMin = i;

        for(int j=i+1; j<size; j++){
            if(v[j] < v[posMin]){
                posMin = j;
            }
        }

        if(posMin != i){
            temp = v[i];
            v[i] = v[posMin];
            v[posMin] = temp;
        }
    }
}


