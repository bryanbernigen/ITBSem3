/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 14 Septermber 2021
Topik praktikum : ADT List Dinamik
Deskripsi       : prapraktikum untuk praktikum 3 pada 16 September 2021 dengan topik yang sama
*/

#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
void CreateListDin(ListDin *l, int capacity)
{
    //input capacity dijamin > 0
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    while (l == NULL)
    {
        BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    }
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
};

void dealocate(ListDin *l)
{
    free(l);
};

/* ********** SELEKTOR (TAMBAHAN) ********** */
int length(ListDin l)
{
    return (NEFF(l));
};

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
{
    return (NEFF(l) - 1);
};

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i)
{
    return (i < CAPACITY(l) && i >= 0);
};
boolean isIdxEff(ListDin l, IdxType i)
{
    return (i < NEFF(l) && i >= 0);
};

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListDin l)
{
    return (NEFF(l) == 0);
};
boolean isFull(ListDin l)
{
    return (NEFF(l) == CAPACITY(l));
};

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void readList(ListDin *l)
{
    int n;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l))
    {
        scanf("%d", &n);
    }
    int i;
    ElType elemen;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &elemen);
        ELMT(*l, i) = elemen;
    }
    NEFF(*l) = n;
};

void displayList(ListDin l)
{
    int i;
    if (!isEmpty(l))
    {

        printf("[");
        for (i = 0; i < NEFF(l) - 1; i++)
        {
            printf("%d,", ELMT(l, i));
        }
        printf("%d]", ELMT(l, i));
    }
    else
    {
        printf("[]");
    }
};

/* ********** OPERATOR ARITMATIKA ********** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    ListDin l3;
    CreateListDin(&l3, NEFF(l1));
    NEFF(l3) = NEFF(l1);
    CAPACITY(l3) = NEFF(l3);
    int i;
    if (plus)
    {
        for (i = 0; i < NEFF(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else
    {
        for (i = 0; i < NEFF(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    //displayList(l3);
    return l3;
};

boolean isListEqual(ListDin l1, ListDin l2)
{
    boolean eq = true;
    int i = 0;
    if (NEFF(l1) != NEFF(l2))
    {
        eq = false;
    }
    while (eq && i < NEFF(l1))
    {
        if (ELMT(l1, i) != ELMT(l2, i))
        {
            eq = false;
        }
        i++;
    }
    return eq;
};

/* ********** SEARCHING ********** */
IdxType indexOf(ListDin l, ElType val)
{
    boolean found = false;
    int index;
    int i = 0;
    if (!isEmpty(l))
    {
        while (!found && i < NEFF(l))
        {
            if (ELMT(l, i) == val)
            {
                index = i;
                found = true;
            }
            i++;
        }
    }
    if (!found)
    {
        return (IDX_UNDEF);
    }
    else
    {
        return index;
    }
};

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
{
    *max = -9999;
    *min = 9999;
    int i;
    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
};

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
{
    CreateListDin(lOut, CAPACITY(lIn));
    int i = 0;
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
};
ElType sumList(ListDin l)
{
    int i = 0;
    ElType jumlah = 0;
    for (i = 0; i < NEFF(l); i++)
    {
        jumlah += ELMT(l, i);
    }
    return jumlah;
};
int countVal(ListDin l, ElType val)
{

    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        int i = 0;
        int jumlah = 0;
        for (i = 0; i < NEFF(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                jumlah += 1;
            }
        }
        return jumlah;
    }
};
boolean isAllEven(ListDin l)
{
    if (isEmpty(l))
    {
        return true;
    }
    else
    {
        int i = 0;
        boolean even = true;
        while (even && i < NEFF(l))
        {
            if (ELMT(l, i) % 2 != 0)
            {
                even = false;
            }
            i++;
        }
        return even;
    }
};

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
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
void insertLast(ListDin *l, ElType val)
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
};
void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l) -= 1;
};

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
{
    CAPACITY(*l) += num;
};
void shrinkList(ListDin *l, int num)
{
    CAPACITY(*l) -= num;
};
void compactList(ListDin *l)
{
    CAPACITY(*l) = NEFF(*l);
};