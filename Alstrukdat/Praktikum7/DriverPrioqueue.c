#include "prioqueue.c"
#include <stdio.h>

int main()
{
    PrioQueue pq;
    ElType temp;
    boolean t;
    int i;
    CreatePrioQueue(&pq);
    t = isEmpty(pq);
    printf("%d\n\n", t);
    for (i = 0; i < 5; i++)
    {
        temp.dService = i;
        temp.id = i;
        temp.score = i;
        temp.tArrival = i;
        enqueue(&pq, temp);
    };
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", pq.buffer[i].id);
    }

    return 0;
}