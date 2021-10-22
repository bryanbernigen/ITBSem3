/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Stack
Deskripsi       : praktikum 8 dengan topik yang sama
*/

#include "stack.c"
#include "tokenmachine.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    Stack s;
    int val, val2;
    int hasil;
    div_t hasildiv;
    startToken();
    CreateStack(&s);
    if (endToken)
    {
        printf("Ekspresi kosong\n");
    }
    else
    {
        while (!endToken)
        {
            if (currentToken.tkn == 'b')
            {
                push(&s, currentToken.val);
                printf("%d\n", currentToken.val);
            }
            else
            {
                pop(&s, &val);
                pop(&s, &val2);
                printf("%d %c %d\n", val2, currentToken.tkn, val);
                if (currentToken.tkn == '+')
                {
                    hasil = val + val2;
                }
                else if (currentToken.tkn == '-')
                {
                    hasil = val - val2;
                }
                else if (currentToken.tkn == '*')
                {
                    hasil = val * val2;
                }
                else if (currentToken.tkn == '/')
                {
                    hasildiv = div(val, val2);
                    hasil = hasildiv.quot;
                }
                else if (currentToken.tkn == '^')
                {
                    hasil = pow(val, val2);
                }
                push(&s, hasil);
                printf("%d\n", hasil);
            }
            advToken();
        }
        pop(&s, &hasil);
        printf("Hasil=%d\n", hasil);
    }
    return 0;
}