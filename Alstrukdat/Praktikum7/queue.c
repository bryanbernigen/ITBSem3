/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Queue
Deskripsi       : prapraktikum untuk praktikum 7  dengan topik yang sama
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
};

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
};

boolean isFull(Queue q)
{
    return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1);
};

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (-IDX_HEAD(q) + IDX_TAIL(q) + 1);
    }
};

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        HEAD(*q) = val;
    }
    else
    {
        //PREKONDISI SOAL: tabel penampung elemen q TIDAK penuh
        if (IDX_TAIL(*q) == CAPACITY - 1)
        {
            //penuh semu jadi pelu digeser
            int i;
            int l;
            l = length(*q);
            for (i = 0; i < l; i++)
            {
                q->buffer[i] = HEAD(*q);
                IDX_HEAD(*q) += 1;
            }
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = i - 1;
        }
        IDX_TAIL(*q) += 1;
        TAIL(*q) = val;
    }
};

void dequeue(Queue *q, ElType *val)
{
    /* I.S. q tidak mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q) += 1;
    }
};

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]");
    }
    else
    {
        int i;
        int l;
        l = length(q);
        printf("[");
        for (i = 0; i < l - 1; i++)
        {
            printf("%d,", HEAD(q));
            IDX_HEAD(q) += 1;
        }
        printf("%d]", TAIL(q));
    }
};