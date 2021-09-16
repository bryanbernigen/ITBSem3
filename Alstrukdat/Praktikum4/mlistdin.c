#include "listdin.h"
#include <stdio.h>

void displayBenar(ListDin l)
{
    printf("%d ", CAPACITY(l));
    displayList(l);
    printf("\n");
}

int main()
{
    int cap, n, i;
    ListDin l;
    int op, num;
    int j, temporary;
    scanf("%d", &cap);
    CreateListDin(&l, cap);
    readList(&l);
    scanf("%d", &n);
    while (n < 0)
    {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d", &num);
            if (NEFF(l) >= CAPACITY(l))
            {
                printf("list sudah penuh\n");
            }
            else
            {
                insertLast(&l, num);
                displayBenar(l);
            }
            break;
        case 2:
            scanf("%d", &num);
            growList(&l, num);
            displayBenar(l);
            break;
        case 3:
            scanf("%d", &num);
            if (num > CAPACITY(l))
            {
                printf("list terlalu kecil\n");
            }
            else
            {
                CAPACITY(l) -= num;
                while (NEFF(l) > CAPACITY(l))
                {
                    deleteLast(&l, &temporary);
                }
                displayBenar(l);
            }
            break;
        case 4:
            compactList(&l);
            displayBenar(l);
            break;
        default:
            break;
        }
    }
    return 0;
}