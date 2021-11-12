/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Stack
Deskripsi       : praktikum 8 dengan topik yang sama
*/

#include "stack.h"
#include "tokenmachine.h"
#include <stdio.h>
#include <math.h>

int main()
{
    // KAMUS DAN DEKLARASI VARIABEL
    Stack isi;
    int val1, val2, res;
    // ALGORITMA
    startToken();
    CreateStack(&isi);
    if (endToken)
        printf("Ekspresi kosong\n");
    else
    {
        while (!endToken)
        {
            if (currentToken.tkn == 'b')
            {
                printf("%d\n", currentToken.val);
                push(&isi, currentToken.val);
            }
            else
            {
                pop(&isi, &val2);
                pop(&isi, &val1);
                if (currentToken.tkn == '+')
                {
                    printf("%d + %d\n", val1, val2);
                    res = val1 + val2;
                    printf("%d\n", res);
                    push(&isi, res);
                }
                else if (currentToken.tkn == '-')
                {
                    printf("%d - %d\n", val1, val2);
                    res = val1 - val2;
                    printf("%d\n", res);
                    push(&isi, res);
                }
                else if (currentToken.tkn == '*')
                {
                    printf("%d * %d\n", val1, val2);
                    res = val1 * val2;
                    printf("%d\n", res);
                    push(&isi, res);
                }
                else if (currentToken.tkn == '/')
                {
                    printf("%d / %d\n", val1, val2);
                    res = val1 / val2;
                    printf("%d\n", res);
                    push(&isi, res);
                }
                else
                {
                    printf("%d ^ %d\n", val1, val2);
                    res = pow(val1, val2);
                    printf("%d\n", res);
                    push(&isi, res);
                }
            }
            advToken();
        }
        pop(&isi, &val1);
        printf("Hasil=%d\n", val1);
    }
}
