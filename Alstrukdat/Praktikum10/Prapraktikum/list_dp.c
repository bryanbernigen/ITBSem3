/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 28 Oktober 2021
Topik praktikum : Linked List Doubole Pointer
Deskripsi       : prapraktikum untuk praktikum 10 dengan topik yang sama
*/

#include "list_dp.h"
#include <stdio.h>
#include <stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    return (FIRST(l) == NULL && LAST(l) == NULL);
};

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
};

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
    return p;
};

void deallocate(Address p)
{
    free(p);
};

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
{
    Address p;
    boolean found;
    p = FIRST(l);
    found = false;
    while (!found && p != NULL)
    {
        if (INFO(p) == val)
        {
            found = true;
        }
        else
        {
            p = NEXT(p);
        }
    }
    if (found)
    {
        return p;
    }
    else
    {
        return NULL;
    }
};

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    Address p;
    p = allocate(val);
    if (p != NULL)
    {
        if (isEmpty(*l))
        {
            NEXT(p) = NULL;
            PREV(p) = NULL;
            FIRST(*l) = p;
            LAST(*l) = p;
        }
        else
        {
            NEXT(p) = FIRST(*l);
            PREV(p) = NULL;
            PREV(FIRST(*l)) = p;
            FIRST(*l) = p;
        }
    }
};
void insertLast(List *l, ElType val)
{
    Address p;
    p = allocate(val);
    if (p != NULL)
    {
        if (isEmpty(*l))
        {
            NEXT(p) = NULL;
            PREV(p) = NULL;
            FIRST(*l) = p;
            LAST(*l) = p;
        }
        else
        {
            PREV(p) = LAST(*l);
            NEXT(p) = NULL;
            NEXT(LAST(*l)) = p;
            LAST(*l) = p;
        }
    }
};

void insertAfter(List *L, Address p, Address pRec)
{
    NEXT(p) = NEXT(pRec);
    PREV(NEXT(pRec)) = p;
    PREV(p) = pRec;
    NEXT(pRec) = p;
};

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    Address p;
    p = FIRST(*l);
    if (NEXT(p) == NULL)
    {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
    }
    else
    {
        FIRST(*l) = NEXT(p);
        PREV(FIRST(*l)) = NULL;
    }
    *val = INFO(p);
    deallocate(p);
};
void deleteLast(List *l, ElType *val)
{
    Address p;
    p = LAST(*l);
    if (PREV(p) == NULL)
    {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
    }
    else
    {
        LAST(*l) = PREV(p);
        NEXT(LAST(*l)) = NULL;
    }
    *val = INFO(p);
    deallocate(p);
};
void deleteAfter(List *l, Address *pDel, Address pRec)
{
    *pDel = NEXT(pRec);
    if (LAST(*l) == NEXT(pRec))
    {
        LAST(*l) = pRec;
        NEXT(pRec) = NULL;
    }
    else
    {
        NEXT(pRec) = NEXT(NEXT(pRec));
        PREV(NEXT(pRec)) = pRec;
    }
};

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
    Address p;
    p = FIRST(l);
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[%d", INFO(p));
        p = NEXT(p);
        while (p != NULL)
        {
            printf(",%d", INFO(p));
            p = NEXT(p);
        }
        printf("]");
    }
};
void displayListBackwards(List l)
{
    Address p;
    p = LAST(l);
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[%d", INFO(p));
        p = PREV(p);
        while (p != NULL)
        {
            printf(",%d", INFO(p));
            p = PREV(p);
        }
        printf("]");
    }
};