#include <stdio.h>
#include <stdlib.h>

//int compare (const void *, const void *);
int confronta(int *a, int *b){

    if(*a % 2 == 0){        // A PARI
        if(*b % 2 != 0){    // B DISPARI
            return -1;
        }
        else{               // B PARI
            return *a - *b;
        }
    }
    else{                   // A DISPARI
        if(*b % 2 != 0){    // B DISPARI
            return *b - *a;
        }
        else{               // B PARI
            return 1;
        }
    }
}

int main()
{
    int tot;
    int *v;

    scanf("%d", &tot);

    v = malloc(sizeof(int) * tot);

    for(int i=0; i<tot; i++){
        scanf("%d", &v[i]);
    }

    qsort(v, tot, sizeof(int), confronta);

    for(int i=0; i<tot; i++){
        printf("%d\n", v[i]);
    }

    return 0;
}
