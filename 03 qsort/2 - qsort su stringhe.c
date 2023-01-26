#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

//int compare (const void *, const void *);
int confronta(const void **a, const void **b){
    return strcmp(*b, *a);
}

int main()
{
    int tot;
    char **v, parola[SIZE];

    scanf("%d", &tot);

    v = malloc(sizeof(char *) * tot);

    for(int i=0; i<tot; i++){
        scanf("%s", parola);
        v[i] = malloc(sizeof(char) * (strlen(parola)+1));
        strcpy(v[i], parola);
    }

    qsort(v, tot, sizeof(char *), confronta);

    for(int i=0; i<tot; i++){
        printf("%s\n", v[i]);
        free(v[i]);
    }

    free(v);

    return 0;
}
