#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;
    int size;
    int max=0, somma=0;

    scanf("%d", &size);
    v = (int *) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        scanf("%d", &v[i]);
    }

    for(int i=0; i<size; i++){
        if(somma > 0){
            somma += v[i];
        }
        else{
            somma = v[i];
        }
        if(somma > max){
            max = somma;
        }
    }

    printf("%d\n", max);

    free(v);

    return 0;
}
