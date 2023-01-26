#include <stdio.h>
#include <stdlib.h>

struct coordinate{
    int x;
    int y;
};
typedef struct coordinate Coordinate;
//////////////////////////////////////////////////////////

int confronta(const void *a1, const void *b1){

    Coordinate **a = (Coordinate **) a1;
    Coordinate **b = (Coordinate **) b1;

    if((*a)->x < (*b)->x){
        return -1;
    }
    else if((*a)->x > (*b)->x){
        return 1;
    }
    else if((*a)->y < (*b)->y){
        return 1;
    }
    else{
        return -1;
    }
}

//////////////////////////////////////////////////////////
int main()
{
    int tot;
    Coordinate **v;

    scanf("%d", &tot);
    v = malloc(sizeof(Coordinate *) * tot);

    for(int i=0; i<tot; i++){
        v[i] = malloc(sizeof(Coordinate));
        scanf("%d %d", &(v[i]->x), &(v[i]->y));
    }

    qsort(v, tot, sizeof(Coordinate *), confronta);

    for(int i=0; i<tot; i++){
        printf("%d %d\n", v[i]->x, v[i]->y);
        free(v[i]);
    }

    free(v);

    return 0;
}
