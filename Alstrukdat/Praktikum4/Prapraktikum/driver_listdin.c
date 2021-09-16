#include "listdin.c"
#include <stdio.h>

int main()
{
    ListDin l, l1, l2, l3;
    int panjang, max, min;
    IdxType index, jumlah;
    boolean ToF;

    CreateListDin(&l, 10);
    printf("%d\n", BUFFER(l));
    readList(&l);
    displayList(l);
    panjang = length(l);
    printf(" %d", panjang);
    //index = getLastIdx(l);
    //printf(" %d", index);

    printf("\n");
    ToF = isIdxValid(l, -1);
    printf("%d ", ToF);
    ToF = isIdxValid(l, 10);
    printf("%d ", ToF);
    ToF = isIdxValid(l, 0);
    printf("%d ", ToF);
    ToF = isIdxValid(l, 9);
    printf("%d ", ToF);

    printf("\n");
    ToF = isIdxEff(l, -1);
    printf("%d ", ToF);
    ToF = isIdxEff(l, 10);
    printf("%d ", ToF);
    ToF = isIdxEff(l, 0);
    printf("%d ", ToF);
    ToF = isIdxEff(l, 3);
    printf("%d ", ToF);

    printf("\n");
    ToF = isEmpty(l);
    printf("%d ", ToF);
    ToF = isFull(l);
    printf("%d ", ToF);

    printf("\n");
    CreateListDin(&l1, 10);
    readList(&l1);
    CreateListDin(&l2, 10);
    ToF = isListEqual(l, l1);
    printf("%d ", ToF);
    index = indexOf(l, -1);
    printf("%d ", index);
    l2 = plusMinusList(l, l1, 1);
    displayList(l2);
    l2 = plusMinusList(l, l1, 0);
    displayList(l2);

    printf("\n");
    extremes(l, &max, &min);
    printf("%d %d ", max, min);
    displayList(l);
    printf("\n");
    sort(&l, 1);
    displayList(l);
    sort(&l, 0);
    displayList(l);

    printf("\n");
    copyList(l, &l3);
    displayList(l3);
    jumlah = sumList(l3);
    printf(" %d ", jumlah);
    jumlah = countVal(l3, 1);
    printf(" %d ", jumlah);
    ToF = isAllEven(l3);
    printf("%d ", ToF);

    dealocate(&l);
    dealocate(&l1);
    dealocate(&l2);
    return 0;
}