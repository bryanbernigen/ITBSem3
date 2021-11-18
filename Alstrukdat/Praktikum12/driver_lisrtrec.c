#include "listrec.c"

int main()
{
    List l = NULL;
    List l2 = NULL;
    List l3 = NULL;
    int angka;
    float avg;
    boolean tof;
    l = konsb(l, -1);
    l = konsb(l, 2);
    l = konsb(l, -3);
    l = konsb(l, 4);
    displayList(l);
    splitOnX(l, 3, &l2, &l3);
    displayList(l2);
    displayList(l3);
    return 0;
}
