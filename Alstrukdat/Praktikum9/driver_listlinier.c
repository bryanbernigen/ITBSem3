#include "list_linked.c"
#include "node.c"
#include <stdio.h>

int main()
{
    Address p1, p2, p3, p4;
    ElType val;
    float avg;
    boolean tof;
    CreateList(&p1);
    CreateList(&p2);
    insertLast(&p1, 1);
    insertLast(&p1, 2);
    insertLast(&p1, 3);
    insertLast(&p1, 4);
    p2 = searchPrec(p1, 5);
    displayList(p2);
    return 0;
}