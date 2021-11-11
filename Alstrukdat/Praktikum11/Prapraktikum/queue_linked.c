/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 5 November 2021
Topik praktikum : Stack dan Queue dengan Linked List
Deskripsi       : prapraktikum untuk praktikum 11 dengan topik yang sama
*/

#include "queue_linked.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
};

boolean isEmpty(Queue q)
{
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
};

int length(Queue q)
{
    Address p;
    int l;
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        l = 1;
        p = ADDR_HEAD(q);
        while (p != ADDR_TAIL(q))
        {
            l++;
            p = NEXT(p);
        }
        return l;
    }
};

/*** Kreator ***/
void CreateQueue(Queue *q)
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
};

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
{
    Address p;
    p = newNode(x);
    if (isEmpty(*q))
    {
        ADDR_HEAD(*q) = p;
        ADDR_TAIL(*q) = p;
    }
    else
    {
        NEXT(ADDR_TAIL(*q)) = p;
        ADDR_TAIL(*q) = p;
    }
};

void dequeue(Queue *q, ElType *x)
{
    Address p;
    p = ADDR_HEAD(*q);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q))
    {
        ADDR_HEAD(*q) = NULL;
        ADDR_TAIL(*q) = NULL;
        *x = INFO(p);
    }
    else
    {
        ADDR_HEAD(*q) = NEXT(p);
        *x = INFO(p);
    }
    free(p);
};