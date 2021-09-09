/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 7 Septermber 2021
Topik praktikum : ADT List
Deskripsi       : prapraktikum untuk praktikum 3 pada 9 September 2021 dengan topik yang sama
*/
#include "listpos.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l)
{
    int i = 0;
    for (i = 0; i < CAPACITY; i++)
    {
        ELMT(*l, i) = VAL_UNDEF;
    }
};

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l)
{
    int i = 0;
    while ((ELMT(l, i) != VAL_UNDEF) && (i < CAPACITY))
    {
        i++;
    }
    return i;
};

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i)
{
    return ((i >= 0) && (i < CAPACITY));
};

boolean isIdxEff(ListPos l, int i)
{
    return ((i >= 0) && (i < length(l)));
};

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l)
{
    return (ELMT(l, 0) == VAL_UNDEF);
};

/* *** Test List penuh *** */
boolean isFull(ListPos l)
{
    return (ELMT(l, CAPACITY - 1) != VAL_UNDEF);
};

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l)
{
    CreateListPos(l);
    int n;
    scanf("%d", &n);
    while ((n < 0) || (n > CAPACITY))
    {
        scanf("%d", &n);
    }
    int i = 0;
    int elemen;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &elemen);
        while (elemen == VAL_UNDEF)
        {
            scanf("%d", &elemen);
        }
        ELMT(*l, i) = elemen;
    }
};

void displayList(ListPos l)
{
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        int count = length(l);
        int i = 0;
        printf("[");
        for (i = 0; i < count; i++)
        {
            if (i != count - 1)
            {
                printf("%d,", ELMT(l, i));
            }
            else
            {
                printf("%d", ELMT(l, i));
            }
        }
        printf("]");
    }
};

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
{
    int count = length(l1);
    int i = 0;
    if (plus)
    {
        for (i = 0; i < count; i++)
        {
            ELMT(l1, i) += ELMT(l2, i);
        }
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            ELMT(l1, i) -= ELMT(l2, i);
        }
    }
    return l1;
};

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2)
{
    boolean eq = true;
    if (length(l1) != length(l2))
    {
        eq = false;
    }
    else
    {

        int i = 0;
        while ((i < length(l1) && eq))
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                eq = false;
            };
            i++;
        }
    }
    return eq;
};

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val)
{
    int i = 0;
    int count = length(l);
    while ((ELMT(l, i) != val) && (i < count))
    {
        i++;
    }
    if (i == count)
    {
        return IDX_UNDEF;
    }
    else
    {
        return i;
    }
};

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min)
{
    int maks = -9999;
    int minim = 9999;
    int i = 0;
    int count = length(l);
    for (i = 0; i < count; i++)
    {
        if (maks < ELMT(l, i))
        {
            maks = ELMT(l, i);
        }
        if (minim > ELMT(l, i))
        {
            minim = ELMT(l, i);
        }
    }
    *max = maks;
    *min = minim;
};

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l)
{
    //Kalo kosong gimana????
    boolean ev = true;
    int i = 0;
    while (ev && (i < length(l)))
    {
        if (ELMT(l, i) % 2 != 0)
        {
            ev = false;
        }
        i++;
    }
    return ev;
};

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc)
{
    if (!isEmpty(*l))
    {
        int i = 0, ii = 1;
        int count = length(*l);
        int sementara;
        if (asc)
        {
            for (i = 0; i < count - 1; i++)
            {
                int idxterkecil = i;
                for (ii = i + 1; ii < count; ii++)
                {
                    if (ELMT(*l, idxterkecil) > ELMT(*l, ii))
                    {

                        idxterkecil = ii;
                    }
                }
                sementara = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, idxterkecil);
                ELMT(*l, idxterkecil) = sementara;
            }
        }
        else
        {
            for (i = 0; i < count - 1; i++)
            {
                int idxterbesar = i;
                for (ii = i + 1; ii < count; ii++)
                {
                    if (ELMT(*l, idxterbesar) < ELMT(*l, ii))
                    {

                        idxterbesar = ii;
                    }
                }
                sementara = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, idxterbesar);
                ELMT(*l, idxterbesar) = sementara;
            }
        }
    }
};

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val)
{
    int index = length(*l);
    ELMT(*l, index) = val;
};

void deleteLast(ListPos *l, ElType *val)
{
    int index = length(*l) - 1;
    *val = ELMT(*l, index);
    ELMT(*l, index) = VAL_UNDEF;
};