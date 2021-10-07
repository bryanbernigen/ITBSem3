#include "queue.c"

int main()
{
    Queue q;
    ElType val;
    boolean ToF;
    int head, tail, l;
    CreateQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    dequeue(&q, &val);
    enqueue(&q, 6);
    l = length(q);
    printf("Head: %d , Tail: %d , Panjang: %d\n", IDX_HEAD(q), IDX_TAIL(q), l);
    displayQueue(q);
    return 0;
}