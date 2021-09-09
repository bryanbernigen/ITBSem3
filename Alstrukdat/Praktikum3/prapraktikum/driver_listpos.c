#include "listpos.c"
#include <stdio.h>

int main()
{
    ListPos list, list2, list3;
    ElType max, min;
    int panjang, index;
    boolean ToF;
    CreateListPos(&list);
    CreateListPos(&list2);
    CreateListPos(&list3);
    panjang = length(list);
    printf("%d ", panjang);
    ToF = isIdxValid(list, 0);
    printf("%d ", ToF);
    ToF = isIdxEff(list, 0);
    printf("%d ", ToF);
    ToF = isEmpty(list);
    printf("%d ", ToF);
    ToF = isFull(list);
    printf("%d ", ToF);
    printf("\n0 0 0 1 0 <-- Harusnya Gini");
    printf("\n");
    readList(&list2);
    displayList(list2);
    ToF = isIdxEff(list2, 1);
    printf("%d ", ToF);
    printf("\n");
    readList(&list);
    list3 = plusMinusTab(list, list2, 0);
    displayList(list3);
    printf("\n");
    ToF = isListEqual(list, list2);
    printf("%d ", ToF);
    index = indexOf(list, 1);
    printf("%d ", index);
    extremes(list, &max, &min);
    printf("%d %d ", max, min);
    ToF = isAllEven(list);
    printf("%d ", ToF);
    printf("\n");
    displayList(list);
    printf("\n");
    sort(&list, 0);
    displayList(list);
    printf("\n");
    insertLast(&list, 99);
    displayList(list);
    printf("\n");
    deleteLast(&list, &max);
    displayList(list);
    printf("\n");
    printf("%d", max);
    return 0;
}