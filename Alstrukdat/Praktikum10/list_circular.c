/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 28 Oktober 2021
Topik praktikum : Linked List Doubole Pointer
Deskripsi       : prapraktikum untuk praktikum 10 dengan topik yang sama
*/

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    /* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (FIRST(l) == NULL);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    FIRST(*l) = NULL;
}
/****************** Manajemen Memori ******************/
Address allocate(ElType val)
{
    /* Mengirimkan Address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
    /* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
    /* Jika alokasi gagal, mengirimkan NULL */
    Address p = (Address)malloc(sizeof(ElmtList));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian Address P */
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
{
    /* Mencari apakah ada elemen list dengan INFO(P)= val */
    /* Jika ada, mengirimkan Address elemen tersebut. */
    /* Jika tidak ada, mengirimkan NULL */
    Address p;
    p = NULL;
    if (!isEmpty(l))
    {
        p = FIRST(l);
        while (NEXT(p) != FIRST(l) && INFO(p) != val)
        {
            p = NEXT(p);
        }
        if (INFO(p) != val)
            p = NULL;
    }
    return p;
}
boolean addrSearch(List l, Address p)
{
    /* Mencari apakah ada elemen list l yang beralamat p */
    /* Mengirimkan true jika ada, false jika tidak ada */
    boolean isFound;
    Address ptrav;
    isFound = false;
    if (!isEmpty(l))
    {
        ptrav = FIRST(l);
        while (ptrav != p && NEXT(ptrav) != FIRST(l))
        {
            ptrav = NEXT(ptrav);
        }
        if (ptrav == p)
            isFound = true;
    }
    return isFound;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    /* I.S. List l terdefinisi, mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
    /* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
    Address p, ptrav;
    p = allocate(val);
    if (isEmpty(*l))
    {
        FIRST(*l) = p;
        NEXT(p) = FIRST(*l);
    }
    else
    {
        ptrav = FIRST(*l);
        while (NEXT(ptrav) != FIRST(*l))
        {
            ptrav = NEXT(ptrav);
        }
        NEXT(ptrav) = p;
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val)
{
    /* I.S. List l terdefinisi, mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
    Address p, ptrav;
    p = allocate(val);
    if (isEmpty(*l))
    {
        FIRST(*l) = p;
        NEXT(p) = FIRST(*l);
    }
    else
    {
        ptrav = FIRST(*l);
        while (NEXT(ptrav) != FIRST(*l))
        {
            ptrav = NEXT(ptrav);
        }
        NEXT(ptrav) = p;
        NEXT(p) = FIRST(*l);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    /* I.S. List l tidak kosong */
    /* F.S. val adalah elemen pertama List l sebelum penghapusan */
    /* Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    /* Jika list baru tidak kosong, Last element menunjuk ke First element baru */
    /* Jika list baru kosong, maka FIRST(*l) = NULL */
    /* Alamat elemen pertama list lama di-dealokasi */
    Address ptrav, pout;
    *val = INFO(FIRST(*l));
    if (NEXT(FIRST(*l)) == FIRST(*l))
    { // 1 element
        deallocate(FIRST(*l));
        FIRST(*l) = NULL;
    }
    else
    {
        ptrav = FIRST(*l);
        while (NEXT(ptrav) != FIRST(*l))
        {
            ptrav = NEXT(ptrav);
        }
        pout = FIRST(*l);
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(ptrav) = FIRST(*l);
        deallocate(pout);
    }
}
void deleteLast(List *l, ElType *val)
{
    /* I.S. List l tidak kosong */
    /* F.S. val adalah elemen terakhir list sebelum penghapusan */
    /* Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
    /* Jika list baru tidak kosong, Last element baru menunjuk ke First element */
    /* Jika list baru kosong, maka FIRST(*l) = NULL */
    /* Alamat elemen terakhir list lama di-dealokasi */
    Address ptrav, prec;

    if (NEXT(FIRST(*l)) == FIRST(*l))
    {
        *val = INFO(FIRST(*l));
        deallocate(FIRST(*l));
        FIRST(*l) = NULL;
    }
    else
    {
        prec = NULL;
        ptrav = FIRST(*l);
        while (NEXT(ptrav) != FIRST(*l))
        {
            prec = ptrav;
            ptrav = NEXT(ptrav);
        }
        *val = INFO(ptrav);
        NEXT(prec) = FIRST(*l);
        deallocate(ptrav);
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
    /* I.S. List l mungkin kosong */
    /* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address ptrav;
    if (isEmpty(l))
        printf("[]");
    else
    {
        printf("[");
        ptrav = FIRST(l);
        while (NEXT(ptrav) != FIRST(l))
        {
            printf("%d,", INFO(ptrav));
            ptrav = NEXT(ptrav);
        }
        printf("%d]", INFO(ptrav));
    }
}