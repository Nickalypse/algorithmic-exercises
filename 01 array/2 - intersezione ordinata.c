#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1, *v2;
    int size1, size2, tot=0;
    int i, j;

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

    i=0;
    j=0;

    while(i<size1 && j<size2){
        if(v1[i] == v2[j]){
            tot++;
            i++;
            j++;
            continue;
        }
        if(v1[i] > v2[j]){
            j++;
            continue;
        }
        if(v1[i] < v2[j]){
            i++;
            continue;
        }
    }

    printf("%d\n", tot);

    free(v1);
    free(v2);

    return 0;
}
