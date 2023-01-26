#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100


int ricerca_bin(char **stringhe, char *stringa, int x, int y);


int main()
{
    int tot, n;
    char **stringhe;
    char stringa[SIZE];

    // Acquisizione totale di stringhe
    scanf("%d", &tot);

    // Allocazione dimanica array contenente stringhe
    stringhe = malloc(sizeof(char *) * tot);

    // Ciclo per acquisizione stringhe
    for(int i=0; i<tot; i++){
        scanf("%s", stringa);
        // Allocazione dinamica della stringa nell'array di stringhe
        stringhe[i] = malloc(sizeof(char) * (strlen(stringa)+1));
        // Copia stringa estratta nell'array
        strcpy(stringhe[i], stringa);
    }

    while(1){

        scanf("%d", &n);
        if(n == 0){
            break;
        }

        scanf("%s", stringa);

        printf("%d\n", ricerca_bin(stringhe, stringa, 0, (tot-1)));
    }

    return 0;
}


int ricerca_bin(char **stringhe, char *stringa, int inf, int sup){

    if(inf > sup){
        return -1;
    }

    if(strcmp(stringa, stringhe[sup]) > 0){
        return -1;
    }
    if(strcmp(stringa, stringhe[inf]) < 0){
        return -1;
    }

    int meta = (inf + sup) / 2;

    if(strcmp(stringa, stringhe[meta]) == 0){
        return meta;
    }

    if(strcmp(stringa, stringhe[meta]) > 0){
        ricerca_bin(stringhe, stringa, meta+1, sup);
    }
    else {
        ricerca_bin(stringhe, stringa, inf, meta-1);
    }
}


