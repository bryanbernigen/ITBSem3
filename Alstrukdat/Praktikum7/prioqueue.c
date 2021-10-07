/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Queue
Deskripsi       : praktikum 7  dengan topik yang sama
*/

#include "prioqueue.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq)
{
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
};

boolean isEmpty(PrioQueue pq)
{
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
};

boolean isFull(PrioQueue pq)
{
    return (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY - 1);
};

int length(PrioQueue pq)
{
    if (isEmpty(pq))
    {
        return 0;
    }
    else
    {
        return (-IDX_HEAD(pq) + IDX_TAIL(pq) + 1);
    }
};

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val)
{
    if (isEmpty(*pq))
    {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        HEAD(*pq) = val;
    }
    else
    {
        //PREKONDISI SOAL: tabel penampung elemen q TIDAK penuh
        if (IDX_TAIL(*pq) == CAPACITY - 1)
        {
            //penuh semu jadi pelu digeser
            int i;
            int l;
            l = length(*pq);
            for (i = 0; i < l; i++)
            {
                pq->buffer[i] = pq->buffer[IDX_HEAD(*pq)];
                IDX_HEAD(*pq) += 1;
            }
            IDX_HEAD(*pq) = 0;
            IDX_TAIL(*pq) = i - 1;
        }
        IDX_TAIL(*pq) += 1;
        TAIL(*pq) = val;
    }
};

void dequeue(PrioQueue *pq, ElType *val)
{
    /* I.S. q tidak mungkin kosong */
    *val = HEAD(*pq);
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq))
    {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*pq) += 1;
    }
};