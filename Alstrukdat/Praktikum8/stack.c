/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Stack
Deskripsi       : prapraktikum untuk praktikum 8 dengan topik yang sama
*/

#include "stack.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
{
    IDX_TOP(*s) = IDX_UNDEF;
};

/* ************ Prototype ************ */
boolean isEmpty(Stack s)
{
    return (IDX_TOP(s) == IDX_UNDEF);
};

boolean isFull(Stack s)
{
    return (IDX_TOP(s) == CAPACITY - 1);
};

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, ElType val)
{
    if (isEmpty(*s))
    {
        IDX_TOP(*s) = 0;
    }
    else
    {
        IDX_TOP(*s) += 1;
    }
    TOP(*s) = val;
};

void pop(Stack *s, ElType *val)
{
    *val = TOP(*s);
    if (IDX_TOP(*s) == 0)
    {
        IDX_TOP(*s) = IDX_UNDEF;
    }
    else
    {
        IDX_TOP(*s) -= 1;
    }
};