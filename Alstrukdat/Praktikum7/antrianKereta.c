/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Queue
Deskripsi       : praktikum 7  dengan topik yang sama
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Queue q;
    int menu, waktu;
    int val;
    float rata_rata = 0;
    int jumlah;
    CreateQueue(&q);
    scanf("%d", &menu);
    while (menu != 0)
    {
        if (menu == 1)
        {
            scanf("%d", &waktu);
            if (isFull(q))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&q, waktu);
            }
        }
        else
        {
            if (isEmpty(q))
            {
                printf("Queue kosong\n");
            }
            else
            {
                dequeue(&q, &val);
            }
        }
        scanf("%d", &menu);
    }
    printf("%d\n", length(q));
    if (isEmpty(q))
    {
        printf("Tidak bisa dihitung\n");
    }
    else
    {
        jumlah = length(q);
        while (!isEmpty(q))
        {
            dequeue(&q, &val);
            rata_rata += val;
        }
        rata_rata /= jumlah;
        printf("%.2f\n", rata_rata);
    }

    return 0;
}