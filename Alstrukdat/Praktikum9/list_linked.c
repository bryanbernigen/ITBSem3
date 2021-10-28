/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Linked List
Deskripsi       : prapraktikum untuk praktikum 9 dengan topik yang sama
*/

#include "list_linked.h"
#include "node.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    FIRST(*l) = NULL;
};

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    return (FIRST(l) == NULL);
};

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
{
    Address p;
    int i;
    p = l;
    for (i = 0; i < idx; i++)
    {
        p = NEXT(p);
    }
    return (INFO(p));
};

void setElmt(List *l, int idx, ElType val)
{
    Address p;
    int i;
    p = *l;
    for (i = 0; i < idx; i++)
    {
        p = NEXT(p);
    }
    INFO(p) = val;
};

int indexOf(List l, ElType val)
{
    Address p;
    int i;
    boolean found = false;
    p = l;
    i = 0;
    while (p != NULL && !found)
    {
        if (INFO(p) == val)
        {
            found = true;
        }
        else
        {
            i++;
            p = NEXT(p);
        }
    }
    if (!found)
    {
        i = IDX_UNDEF;
    }
    return i;
};

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    Address p;
    p = newNode(val);
    if (p == NULL)
    {
        return;
    }
    if (isEmpty(*l))
    {
        FIRST(*l) = p;
    }
    else
    {
        NEXT(p) = *l;
        FIRST(*l) = p;
    }
};

void insertLast(List *l, ElType val)
{
    Address p, q;
    p = newNode(val);
    if (l == NULL)
    {
        return;
    }
    if (isEmpty(*l))
    {
        FIRST(*l) = p;
    }
    else
    {
        q = *l;
        while (NEXT(q) != NULL)
        {
            q = NEXT(q);
        }
        NEXT(q) = p;
    }
};

void insertAt(List *l, ElType val, int idx)
{
    Address p, q;
    p = newNode(val);
    if (p == NULL)
    {
        return;
    }
    if (idx == 0)
    {
        NEXT(p) = *l;
        FIRST(*l) = p;
    }
    else
    {
        q = *l;
        while (idx > 1)
        {
            q = NEXT(q);
            idx--;
        }
        NEXT(p) = NEXT(q);
        NEXT(q) = p;
    }
};

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    Address p;
    p = *l;
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
};

void deleteLast(List *l, ElType *val)
{
    Address p, q;
    if (NEXT(*l) == NULL)
    {
        p = *l;
        *val = INFO(p);
        FIRST(*l) = NULL;
        free(p);
    }
    else
    {
        p = *l;
        q = NEXT(*l);
        while (NEXT(q) != NULL)
        {
            p = NEXT(p);
            q = NEXT(q);
        }
        *val = INFO(q);
        NEXT(p) = NULL;
        free(q);
    }
};

void deleteAt(List *l, int idx, ElType *val)
{
    Address p, q;
    if (idx == 0)
    {
        p = *l;
        *val = INFO(p);
        FIRST(*l) = NEXT(p);
    }
    else
    {
        p = *l;
        q = NEXT(*l);
        while (idx > 1)
        {
            p = NEXT(p);
            q = NEXT(q);
            idx--;
        }
        *val = INFO(q);
        NEXT(p) = NEXT(q);
    }
};

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
    Address p;
    p = l;
    if (isEmpty(p))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        while (NEXT(p) != NULL)
        {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d]", INFO(p));
    }
};

int length(List l)
{
    int i;
    Address p;
    p = l;
    if (isEmpty(p))
    {
        return 0;
    }
    else
    {
        i = 1;
        while (NEXT(p) != NULL)
        {
            i++;
            p = NEXT(p);
        }
        return i;
    }
};

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
{
    Address p;
    boolean found;
    found = false;
    p = L;
    while (p != NULL && !found)
    {
        if (p == P)
        {
            found = true;
        }
        else
        {
            p = NEXT(p);
        }
    }
    return found;
};

Address searchPrec(List L, ElType X)
{
    Address p, q;
    boolean found;
    p = L;
    if (INFO(p) == X)
    {
        return NULL;
    }
    else
    {
        q = NEXT(p);
        while (!found && q != NULL)
        {
            if (INFO(q) == X)
            {
                found = true;
            }
            else
            {
                p = NEXT(p);
                q = NEXT(q);
            }
        }
        if (!found)
        {
            return NULL;
        }
        else
        {
            return p;
        }
    }
};

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List l)
{
    Address p;
    ElType nmax;
    nmax = -9999;
    p = l;
    while (p != NULL)
    {
        if (INFO(p) > nmax)
        {
            nmax = INFO(p);
        }
        p = NEXT(p);
    }
    return nmax;
};

Address adrMax(List l)
{
    Address p, admax;
    ElType nmax;
    nmax = -9999;
    p = l;
    admax = p;
    while (p != NULL)
    {
        if (INFO(p) > nmax)
        {
            nmax = INFO(p);
            admax = p;
        }
        p = NEXT(p);
    }
    return admax;
};

ElType min(List l)
{
    Address p;
    ElType nmin;
    nmin = 9999;
    p = l;
    while (p != NULL)
    {
        if (INFO(p) < nmin)
        {
            nmin = INFO(p);
        }
        p = NEXT(p);
    }
    return nmin;
};

Address adrMin(List l)
{
    Address p, admin;
    ElType nmin;
    nmin = 9999;
    p = l;
    admin = p;
    while (p != NULL)
    {
        if (INFO(p) < nmin)
        {
            nmin = INFO(p);
            admin = p;
        }
        p = NEXT(p);
    }
    return admin;
};

float average(List l)
{
    Address p;
    float rata2;
    int banyak, jumlah;
    p = l;
    banyak = 0;
    jumlah = 0;
    while (p != NULL)
    {
        banyak++;
        jumlah += INFO(p);
        p = NEXT(p);
    }
    rata2 = (float)jumlah / banyak;
    return rata2;
};

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
{
    List l;
    Address p;
    CreateList(&l);
    p = l1;
    while (p != NULL)
    {
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL)
    {
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }
    return l;
};

void delAll(List *l)
{
    ElType val;
    while (*l != NULL)
    {
        deleteFirst(l, &val);
    }
};

void inverseList(List *l)
{
    List p;
    ElType val;
    CreateList(&p);
    while (length(*l) != 0)
    {
        deleteLast(l, &val);
        insertLast(&p, val);
    }
    *l = p;
};

List fInverseList(List l)
{
    Address p, q;
    ElType val;
    CreateList(&p);
    q = l;
    while (q != NULL)
    {
        val = INFO(q);
        insertFirst(&p, val);
        q = NEXT(q);
    }
    return p;
};

void copyList(List *l1, List *l2)
{
    *l2 = *l1;
};

List fCopyList(List l)
{
    Address temp;
    Address p;
    ElType val;
    CreateList(&temp);
    p = l;
    while (p != NULL)
    {
        val = INFO(p);
        insertLast(&temp, val);
        p = NEXT(p);
    }
    return temp;
};

void cpAllocList(List lIn, List *lOut)
{
    *lOut = fCopyList(lIn);
};

void splitList(List *l1, List *l2, List l)
{
    int leng;
    int i;
    int L_l1;
    div_t splitL;
    ElType val;
    Address p;
    CreateList(l1);
    CreateList(l2);
    leng = length(l);
    splitL = div(leng, 2);
    L_l1 = splitL.quot;
    p = l;
    for (size_t i = 0; i < L_l1; i++)
    {
        val = INFO(p);
        insertLast(l1, val);
        p = NEXT(p);
    }
    while (p != NULL)
    {
        val = INFO(p);
        insertLast(l2, val);
        p = NEXT(p);
    }
};