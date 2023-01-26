#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1, *v2, *v3;
    int size1, size2;
    int i, j, k;

    scanf("%d", &size1);
    v1 = (int *) malloc(size1 * sizeof(int));
    for(i=0; i<size1; i++){
        scanf("%d", &v1[i]);
    }

    scanf("%d", &size2);
    v2 = (int *) malloc(size2 * sizeof(int));
    for(i=0; i<size2; i++){
        scanf("%d", &v2[i]);
    }

    // Creazjone vettore unione
    v3 = (int *) malloc((size1 + size2) * sizeof(int));

    i=0;
    j=0;
    k=0;

    while(i<size1 && j<size2){
        if(v1[i] < v2[j]){
            v3[k] = v1[i];
            i++;
        }
        else {
            v3[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < size1){
        v3[k] = v1[i];
        i++;
        k++;
    }

    while(j < size2){
        v3[k] = v2[j];
        j++;
        k++;
    }

    for(k=0; k<size1+size2; k++){
        printf("%d\n", v3[k]);
    }

    free(v1);
    free(v2);
    free(v3);

    return 0;
}
