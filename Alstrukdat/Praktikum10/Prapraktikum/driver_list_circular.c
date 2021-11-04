#include "list_dp.c"
#include <stdio.h>

int main()
{
    List p1, p2;
    ElType val;
    CreateList(&p1);
    CreateList(&p2);
    insertFirst(&p1, 1);
    deleteLast(&p1, &val);
    printf("%d", val);
    displayList(p1);
    displayList(p2);
    return 0;
}