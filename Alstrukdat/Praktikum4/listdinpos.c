/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 16 Septermber 2021
Topik praktikum : ADT List Dinamik
Deskripsi       : praktikum 4 pada 16 September 2021 dengan topik yang sama
*/
#include "listdinpos.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
void CreateListDin(ListDin *l, int capacity)
{
    BUFFER(*l) = (ElType *)malloc((capacity) * sizeof(ElType));
    while (l == NULL)
    {
        BUFFER(*l) = (ElType *)malloc((capacity) * sizeof(ElType));
    }
    CAPACITY(*l) = capacity;
    int i;
    for (i = 0; i < capacity; i++)
    {
        ELMT(*l, i) = VAL_UNDEF;
    }
};

void dealocate(ListDin *l)
{
    free(l);
};

/* ********** SELEKTOR (TAMBAHAN) ********** */
int length(ListDin l)
{
    int i = 0;
    while ((ELMT(l, i) != VAL_UNDEF) && (i < CAPACITY(l)))
    {
        i++;
    }
    return i;
};

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
{
    int i = 0;
    while (i < CAPACITY(l) && ELMT(l, i) != VAL_UNDEF)
    {
        i++;
    }
    return i - 1;
};

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
{
    return (i >= 0 && i < CAPACITY(l));
};
boolean isIdxEff(ListDin l, IdxType i)
{
    IdxType last;
    last = getLastIdx(l);
    return (i >= 0 && i <= last);
};

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListDin l)
{
    return (ELMT(l, 0) == VAL_UNDEF);
};
boolean isFull(ListDin l)
{
    return (ELMT(l, CAPACITY(l) - 1) != VAL_UNDEF);
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
};

void displayList(ListDin l)
{
    int i;
    if (!isEmpty(l))
    {

        printf("[");
        for (i = 0; i < length(l); i++)
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
    CreateListDin(&l3, length(l1));
    CAPACITY(l3) = length(l3);
    int i;
    if (plus)
    {
        for (i = 0; i < length(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else
    {
        for (i = 0; i < length(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
};

/* ********** OPERATOR RELASIONAL ********** */
boolean isListEqual(ListDin l1, ListDin l2)
{
    boolean eq = true;
    int i = 0;
    if (length(l1) != length(l2))
    {
        eq = false;
    }
    while (eq && i < length(l1))
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
        while (!found && i < length(l))
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
        return (VAL_UNDEF);
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
    for (i = 0; i < length(l); i++)
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

void copyList(ListDin lIn, ListDin *lOut)
{
    CreateListDin(lOut, CAPACITY(lIn));
    int i = 0;
    for (i = 0; i < length(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
};
ElType sumList(ListDin l)
{
    int i = 0;
    ElType jumlah = 0;
    for (i = 0; i < length(l); i++)
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
        for (i = 0; i < length(l); i++)
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
        while (even && i < length(l))
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
    ELMT(*l, length(*l)) = val;
};
void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l, length(*l) - 1);
    ELMT(*l, length(*l)) = VAL_UNDEF;
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
    CAPACITY(*l) = length(*l);
};