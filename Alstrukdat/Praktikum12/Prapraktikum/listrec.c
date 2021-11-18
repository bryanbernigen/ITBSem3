/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 11 November 2021
Topik praktikum : List Rekursif
Deskripsi       : prapraktikum untuk praktikum 12 dengan topik yang sama
*/

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
};

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
{
    return (l == NULL);
};

int isOneElmt(List l)
{
    if (isEmpty(l))
    {
        return false;
    }
    else
    {
        return (NEXT(l) == NULL);
    }
};

ElType head(List l)
{
    if (!isEmpty(l))
    {
        return (INFO(l));
    }
};

List tail(List l)
{
    if (isEmpty(l))
    {
        return NULL;
    }
    else
    {
        return NEXT(l);
    }
};

List konso(List l, ElType e)
{
    Address p;
    p = newNode(e);
    if (p != NULL)
    {
        if (!isEmpty(l))
        {
            NEXT(p) = l;
        }
        l = p;
    }
    return l;
};

List konsb(List l, ElType e)
{
    Address p, q;
    p = newNode(e);
    if (p != NULL)
    {
        if (isEmpty(l))
        {
            l = p;
        }
        else
        {
            q = l;
            while (NEXT(q) != NULL)
            {
                q = NEXT(q);
            }
            NEXT(q) = p;
        }
    }
    return l;
};

int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
};

void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", head(l));
        if (tail(l) != NULL)
        {
            displayList(tail(l));
        }
    }
};