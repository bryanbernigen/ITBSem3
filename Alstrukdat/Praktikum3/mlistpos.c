/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 7 Septermber 2021
Topik praktikum : ADT List
Deskripsi       :  praktikum 3 pada 9 September 2021 dengan topik ADT List
*/

#include <stdio.h>
#include <stdlib.h>
#include "listpos.h"

int main()
{
    //kamus
    ListPos l;
    int x, index, maxval, minval, med;

    readList(&l);
    displayList(l);
    printf("\n");

    scanf("%d", &x);
    index = indexOf(l, x);
    if (index == IDX_UNDEF)
    {
        printf("%d tidak ada", x);
    }
    else
    {
        printf("%d", index);
    }
    printf("\n");

    extremes(l, &maxval, &minval);
    div_t hasilDiv;
    hasilDiv = div(length(l), 2);
    sort(&l, 1);
    if (!isEmpty(l))
    {
        if (length(l) % 2 == 0)
        {
            med = ELMT(l, hasilDiv.quot - 1);
        }
        else
        {

            med = ELMT(l, (hasilDiv.quot + 1) - 1);
        }
        if (x == maxval)
        {
            printf("maksimum\n");
        }
        if (x == minval)
        {
            printf("minimum\n");
        }
        if (x == med)
        {
            printf("median\n");
        }
    }
    return 0;
}