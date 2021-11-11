/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 11 November 2021
Topik praktikum : Stack dan Queue dengan Linked List
Deskripsi       : praktikum 11 dengan topik yang sama
*/

#include "stack_linked.h"
#include <stdio.h>

int main()
{
    int Panjang1, Panjang2;
    int i;
    int inpt;
    ElType val;
    ElType val1, val2;
    Stack S1, S2;
    boolean same;
    scanf("%d %d", &Panjang1, &Panjang2);
    if (Panjang1 == 0 && Panjang2 == 0)
    {
        printf("Sama\n");
    }
    else
    {
        CreateStack(&S1);
        CreateStack(&S2);
        for (i = 0; i < Panjang1; i++)
        {
            scanf("%d", &inpt);
            if (inpt == 0)
            {
                if (!isEmpty(S1))
                {
                    pop(&S1, &val);
                }
            }
            else
            {
                push(&S1, inpt);
            }
        }
        for (i = 0; i < Panjang2; i++)
        {
            scanf("%d", &inpt);
            if (inpt == 0)
            {
                if (!isEmpty(S2))
                {
                    pop(&S2, &val);
                }
            }
            else
            {
                push(&S2, inpt);
            }
        }

        same = true;
        while (!isEmpty(S1) && same)
        {
            if (isEmpty(S2))
            {
                same = false;
            }
            else
            {
                pop(&S1, &val1);
                pop(&S2, &val2);
                if (val1 != val2)
                {
                    same = false;
                }
            }
        }
        while (!isEmpty(S2) && same)
        {
            if (isEmpty(S1))
            {
                same = false;
            }
            else
            {
                pop(&S1, &val1);
                pop(&S2, &val2);
                if (val1 != val2)
                {
                    same = false;
                }
            }
        }
        if (same)
        {
            printf("Sama\n");
        }
        else
        {
            printf("Tidak sama\n");
        }
    }
    return 0;
}
