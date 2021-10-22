/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Stack
Deskripsi       : praktikum 8 dengan topik yang sama
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Stack s1, s2, sh;
    char CC;
    int CI;
    int carry;
    int val1, val2, valhasil;
    CreateStack(&s1);
    CreateStack(&s2);
    CreateStack(&sh);
    scanf("%c", &CC);
    while (CC != '#')
    {
        CI = (int)CC - 48;
        push(&s1, CI);
        scanf("%c", &CC);
    }
    while ((int)CC - 48 < 0)
    {
        scanf("%c", &CC);
    }
    while (CC != '#')
    {
        CI = (int)CC - 48;
        push(&s2, CI);
        scanf("%c", &CC);
    }
    carry = 0;
    while (!isEmpty(s1) || !isEmpty(s2))
    {
        if (!isEmpty(s1))
        {
            pop(&s1, &val1);
        }
        else
        {
            val1 = 0;
        }
        if (!isEmpty(s2))
        {
            pop(&s2, &val2);
        }
        else
        {
            val2 = 0;
        }
        valhasil = val1 + val2 + carry;
        carry = 0;
        if (valhasil >= 10)
        {
            valhasil -= 10;
            carry = 1;
        }
        push(&sh, valhasil);
    }
    if (carry != 0 && !isFull(sh))
    {
        push(&sh, carry);
    }
    while (!isEmpty(sh))
    {
        pop(&sh, &valhasil);
        printf("%d", valhasil);
    }
    printf("\n");
    return 0;
}