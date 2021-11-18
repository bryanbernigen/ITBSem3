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

ElType maxList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        if (head(l) > maxList(tail(l)))
        {
            return head(l);
        }
        else
        {
            return maxList(tail(l));
        }
    }
};

ElType minList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        if (head(l) < minList(tail(l)))
        {
            return head(l);
        }
        else
        {
            return minList(tail(l));
        }
    }
};

ElType sumList(List l)
{
    if (isOneElmt(l))
    {
        return head(l);
    }
    else
    {
        return (head(l) + sumList(tail(l)));
    }
};

float averageList(List l)
{
    int banyak;
    float jumlah;
    banyak = length(l);
    jumlah = sumList(l);
    return jumlah / banyak;
};

List inverseList(List l)
{
    List temp;
    if (isOneElmt(l))
    {
        return l;
    }
    else
    {
        temp = konsb(inverseList(tail(l)), head(l));
    }
    return temp;
};

void splitPosNeg(List l, List *l1, List *l2)
{
    if (!isEmpty(l))
    {
        if (head(l) >= 0)
        {
            *l1 = konsb(*l1, head(l));
            splitPosNeg(tail(l), l1, l2);
        }
        else
        {
            *l2 = konsb(*l2, head(l));
            splitPosNeg(tail(l), l1, l2);
        }
    }
};

void splitOnX(List l, ElType x, List *l1, List *l2)
{
    if (!isEmpty(l))
    {
        if (head(l) < x)
        {
            *l1 = konsb(*l1, head(l));
            splitOnX(tail(l), x, l1, l2);
        }
        else
        {
            *l2 = konsb(*l2, head(l));
            splitOnX(tail(l), x, l1, l2);
        }
    }
};

int compareList(List l1, List l2)
{
    if (length(l1) > length(l2))
    {
        return 1;
    }
    if (length(l1) < length(l2))
    {
        return -1;
    }
    if (isOneElmt(l1) && isOneElmt(l2))
    {
        if (head(l1) == head(l2))
        {
            return 0;
        }
        else if (head(l1) < head(l2))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (head(l1) == head(l2))
        {
            return compareList(tail(l1), tail(l2));
        }
        else if (head(l1) < head(l2))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
};

boolean isAllExist(List l1, List l2)
{
    boolean temp;
    if (isEmpty(l1) || isEmpty(l2))
    {
        return false;
    }
    else
    {
        if (isOneElmt(l1))
        {
            if (head(l1) == head(l2))
            {
                return true;
            }
            else
            {
                return isAllExist(l1, tail(l2));
            }
        }
        else
        {
            if (head(l1) == head(l2))
            {
                temp = true;
            }
            else
            {
                temp = isAllExist(l1, tail(l2));
            }
            if (temp)
            {
                isAllExist(tail(l1), l2);
            }
            else
            {
                return false;
            }
        }
    }
};