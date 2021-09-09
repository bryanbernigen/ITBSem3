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

    ListPos l, lasc, ldsc;
    int i;

    readList(&l);
    CreateListPos(&lasc);
    CreateListPos(&ldsc);
    for (i = 0; i < length(l); i++)
    {
        ELMT(lasc, i) = ELMT(l, i);
        ELMT(ldsc, i) = ELMT(l, i);
    }
    sort(&lasc, 1);
    sort(&ldsc, 0);
    if (isListEqual(lasc, ldsc))
    {
        printf("Static Monotonic List\n");
    }
    else
    {
        if (isListEqual(l, lasc))
        {
            printf("Non-descending Monotonic List\n");
        }
        else
        {
            if (isListEqual(l, ldsc))
            {
                printf("Non-ascending Monotonic List\n");
            }
            else
            {
                printf("Non-monotonic List\n");
            }
        }
    }

    return 0;
}