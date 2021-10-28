/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Linked List
Deskripsi       : prapraktikum untuk praktikum 9 dengan topik yang sama
*/

#include "list_linked.h"
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