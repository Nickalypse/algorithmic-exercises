#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

struct parola{
    char *s;
    int lunghezza;
};

typedef struct parola Parola;
///////////////////////////////////////////////////

int confronta(const void *a1, const void *b1){

    Parola **a = (Parola **) a1;
    Parola **b = (Parola **) b1;

    if((*a)->lunghezza < (*b)->lunghezza){
        return -1;
    }
    if((*a)->lunghezza > (*b)->lunghezza){
        return 1;
    }

    return strcmp((*a)->s, (*b)->s);
}

///////////////////////////////////////////////////
int main()
{
    int tot;
    char stringa[SIZE];
    Parola **v;

    scanf("%d", &tot);
    v = malloc(sizeof(Parola *) * tot);

    for(int i=0; i<tot; i++){

        // Alloco struct in cella del vettore
        v[i] = malloc(sizeof(Parola));

        // Acquisizione singola parola
        scanf("%s", stringa);

        // Memorizzazione in struct di lunghezza parola
        v[i]->lunghezza = strlen(stringa);

        // Allocazione spazio minimo per parola
        char *s = malloc(sizeof(char) * (v[i]->lunghezza + 1));

        // Copia parola in nuova locazione
        strcpy(s, stringa);

        // Memorizzazione puntatore a parola in struct
        v[i]->s = s;
    }

    qsort(v, tot, sizeof(Parola *), confronta);

    for(int i=0; i<tot; i++){
        printf("%s\n", v[i]->s);
        free(v[i]->s);
        free(v[i]);
    }

    free(v);

    return 0;
}


