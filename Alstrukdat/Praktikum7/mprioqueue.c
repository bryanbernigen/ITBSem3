/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Queue
Deskripsi       : praktikum 7  dengan topik yang sama
*/

#include "prioqueue.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    PrioQueue pq;
    ElType tempEl, tempEl1;
    int mat[CAPACITY][4];
    int T, I, M, D;
    int jumlah;
    int totalTime = 0;
    int currentTime = 0;
    int startTime = 0;
    int i;
    int dasproterbesar, idxterbesar;
    scanf("%d", &jumlah);
    if (jumlah == 0)
    {
        printf("Tidak ada layanan\n");
    }
    else
    {
        //ngisi queue
        CreatePrioQueue(&pq);
        for (i = 0; i < jumlah; i++)
        {
            scanf("%d %d %d %d", &T, &I, &M, &D);
            tempEl.tArrival = T;
            tempEl.id = I;
            tempEl.score = M;
            tempEl.dService = D;
            enqueue(&pq, tempEl);
        }
        currentTime = pq.buffer[IDX_HEAD(pq)].tArrival;
        while (!isEmpty(pq))
        {
            if (currentTime >= pq.buffer[IDX_HEAD(pq)].tArrival)
            {
                dasproterbesar = 0;
                idxterbesar = 0;
                for (i = 0; i < length(pq); i++)
                {
                    if (pq.buffer[IDX_HEAD(pq) + i].tArrival <= currentTime)
                    {
                        if (dasproterbesar < pq.buffer[IDX_HEAD(pq) + i].score)
                        {
                            dasproterbesar = pq.buffer[IDX_HEAD(pq) + i].score;
                            idxterbesar = i;
                        }
                    }
                }
                if (idxterbesar != 0)
                {
                    tempEl1 = pq.buffer[IDX_HEAD(pq)];
                    pq.buffer[IDX_HEAD(pq)] = pq.buffer[IDX_HEAD(pq) + idxterbesar];
                    pq.buffer[IDX_HEAD(pq) + idxterbesar] = tempEl1;
                }
                printf("%d %d %d\n", currentTime, pq.buffer[IDX_HEAD(pq)].id, -pq.buffer[IDX_HEAD(pq)].tArrival + currentTime);
                currentTime += pq.buffer[IDX_HEAD(pq)].dService;
                dequeue(&pq, &tempEl);
            }
        }
    }

    return 0;
}