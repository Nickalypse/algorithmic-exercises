#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1, *v2;
    int size, tot=0;

    scanf("%d", &size);
    v1 = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        scanf("%d", &v1[i]);
    }

    scanf("%d", &size);
    v2 = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        scanf("%d", &v2[i]);
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(v1[i] == v2[j]){
                tot++;
                break;
            }
        }
    }

    printf("%d\n", tot);

    free(v1);
    free(v2);

    return 0;
}
