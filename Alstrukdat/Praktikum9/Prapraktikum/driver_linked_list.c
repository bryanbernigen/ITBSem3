#include "list_linked.c"
#include "node.c"
#include <stdio.h>

int main()
{
    Address p, p2, p3, p4;
    ElType val;
    boolean tof;
    int l, idx;
    CreateList(&p);
    CreateList(&p2);
    CreateList(&p3);
    CreateList(&p4);
    displayList(p);
    insertFirst(&p, 1);
    insertFirst(&p, 1);
    displayList(p);
    return 0;
}