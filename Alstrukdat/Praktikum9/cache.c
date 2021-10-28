/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Linked List
Deskripsi       : prapraktikum untuk praktikum 9 dengan topik yang sama
*/

#include "list_linked.h"
#include "node.h"
#include <stdio.h>

int main()
{
    int ukuran, jumlah_operasi, input_user;
    int i, j;
    boolean found;
    Address l, p;
    ElType val;
    scanf("%d", &ukuran);
    CreateList(&l);
    for (size_t i = 0; i < ukuran; i++)
    {
        insertLast(&l, i + 1);
    }
    scanf("%d", &jumlah_operasi);
    for (i = 0; i < jumlah_operasi; i++)
    {
        scanf("%d", &input_user);
        found = false;
        j = 0;
        p = l;
        while (!found && p != NULL)
        {
            if (INFO(p) == input_user)
            {
                found = true;
            }
            else
            {
                j++;
                p = NEXT(p);
            }
        }
        if (found)
        {
            printf("hit ");
            deleteAt(&l, j, &val);
            insertFirst(&l, val);
        }
        else
        {
            if (INFO(l) == input_user)
            {
                printf("hit ");
            }
            else
            {
                printf("miss ");
                deleteLast(&l, &val);
                insertFirst(&l, input_user);
            }
        }
        displayList(l);
        printf("\n");
    }
    return 0;
}