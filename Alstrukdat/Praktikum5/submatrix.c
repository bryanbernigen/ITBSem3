/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 17 Septermber 2021
Topik praktikum : Matrix
Deskripsi       : praktikum 5 pada 23 September 2021 dengan topik yang sama
*/

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int TC;
    int i, j, k, l, o;
    scanf("%d", &TC);
    for (i = 0; i < TC; i++)
    {
        Matrix m;
        int N, M, maxkasus = 0;
        scanf("%d", &N);
        readMatrix(&m, N, N);
        scanf("%d", &M);
        for (j = 0; j <= N - M; j++)
        {
            for (k = 0; k <= N - M; k++)
            {
                int tempkasus = 0;
                for (l = 0; l < M; l++)
                {
                    for (o = 0; o < M; o++)
                    {
                        tempkasus += ELMT(m, j + l, k + o);
                    }
                }
                if (tempkasus > maxkasus)
                {
                    maxkasus = tempkasus;
                }
            }
        }
        printf("%d\n", maxkasus);
    }
}