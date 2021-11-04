/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 28 Oktober 2021
Topik praktikum : Linked List Doubole Pointer
Deskripsi       : prapraktikum untuk praktikum 10 dengan topik yang sama
*/

#include "list_circular.h"
#include <stdio.h>

void deleteRR(List *l, ElType tQ)
{
    /* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
    - jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
    - jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
    /* Jika l kosong, cetak "List kosong" */
    /* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
    L terdefinisi, mungkin kosong. */
    /* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
    l mungkin menjadi kosong. */
    Address p;
    ElType val;
    if (!isEmpty(*l))
    {
        p = FIRST(*l);
        while (NEXT(p) != FIRST(*l))
        {
            p = NEXT(p);
        }
        if (INFO(p) > tQ)
        {
            printf("%d\n", tQ);
            INFO(p) = INFO(p) - tQ;
            FIRST(*l) = p;
        }
        else
        {
            printf("%d\n", INFO(p));
            deleteLast(l, &val);
        }
    }
    else
    {
        printf("List kosong\n");
    }
};

float average(List l)
{
    /* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */
    Address p;
    float rata2;
    int total;
    int jumlah;
    p = FIRST(l);
    total = INFO(p);
    jumlah = 1;
    while (NEXT(p) != FIRST(l))
    {
        p = NEXT(p);
        total += INFO(p);
        jumlah += 1;
    }
    rata2 = (float)total / jumlah;
    return rata2;
};

int main()
{
    int time_slice;
    int waktu_proses;
    char operasi;
    ElType val;
    Address p;
    List l;
    CreateList(&l);
    time_slice = 0;
    while (time_slice <= 0)
    {
        scanf("%d", &time_slice);
    }
    while (operasi != 'F')
    {
        scanf(" %c", &operasi);
        if (operasi == 'A')
        {
            scanf("%d", &waktu_proses);
            if (waktu_proses > 0)
            {
                insertFirst(&l, waktu_proses);
            }
        }
        else if (operasi == 'D')
        {
            deleteRR(&l, time_slice);
        }
        else if (operasi != 'F')
        {
            printf("Kode salah\n");
        }
    };
    if (isEmpty(l))
    {
        printf("Proses selesai\n");
    }
    else
    {
        printf("%.2f\n", average(l));
    }
    return 0;
}