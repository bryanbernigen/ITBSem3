/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 11 November 2021
Topik praktikum : Stack dan Queue dengan Linked List
Deskripsi       : praktikum 11 dengan topik yang sama
*/

#include "queue_linked.h"
#include <stdio.h>

int main()
{
    int i;
    int n_pengguna;
    int waktu_masuk;
    Queue q;
    Address p;
    ElType val;

    CreateQueue(&q);
    scanf("%d", &n_pengguna);
    scanf("%d", &waktu_masuk);
    enqueue(&q, waktu_masuk);
    printf("%d\n", length(q));
    for (i = 0; i < n_pengguna - 1; i++)
    {
        scanf("%d", &waktu_masuk);
        enqueue(&q, waktu_masuk);
        while (waktu_masuk - HEAD(q) > 300)
        {
            dequeue(&q, &val);
        }
        printf("%d\n", length(q));
    }
    return 0;
}