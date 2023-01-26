#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_WORD 100

void insertion_sort(char **v, int size);

int main()
{
    char **v;
    int size;

    scanf("%d", &size);
    v = (char **) malloc(size * sizeof(char *));
    for(int i=0; i<size; i++){
        v[i] = (char *) malloc(SIZE_WORD * sizeof(char));
        scanf("%s", v[i]);
    }

    insertion_sort(v, size);

    for(int i=0; i<size; i++){
        printf("%s\n", v[i]);
        free(v[i]);
    }

    free(v);

    return 0;
}

void insertion_sort(char **v, int size){

    char word[SIZE_WORD];
    int j;

    for(int i=1; i<size; i++){

        strcpy(word, v[i]);
        j = i-1;

        while((j >= 0) && (strcmp(v[j], word) > 0)){
            strcpy(v[j+1], v[j]);
            j--;
        }

        strcpy(v[j+1], word);
    }
}

