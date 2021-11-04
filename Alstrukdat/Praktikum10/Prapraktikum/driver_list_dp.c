#include "list_dp.c"
#include <stdio.h>

int main()
{
    List p1, p2;
    CreateList(&p1);
    CreateList(&p2);
    insertFirst(&p1, 1);
    insertFirst(&p1, 2);
    insertLast(&p2, 1);
    insertLast(&p2, 2);
    displayList(p1);
    displayListBackwards(p1);
    displayList(p2);
    displayListBackwards(p2);
    return 0;
}