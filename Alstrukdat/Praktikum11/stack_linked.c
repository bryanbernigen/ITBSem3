/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 5 November 2021
Topik praktikum : Stack dan Queue dengan Linked List
Deskripsi       : prapraktikum untuk praktikum 11 dengan topik yang sama
*/

#include "stack_linked.h"
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

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
{
    return (ADDR_TOP(s) == NULL);
};

void CreateStack(Stack *s)
{
    ADDR_TOP(*s) = NULL;
};

void push(Stack *s, ElType x)
{
    Address p;
    p = newNode(x);
    if (isEmpty(*s))
    {
        ADDR_TOP(*s) = p;
    }
    else
    {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
};

void pop(Stack *s, ElType *x)
{
    Address p;
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(p);
    *x = INFO(p);
    free (p);
};