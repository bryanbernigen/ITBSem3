#include <stdio.h>
#include "garis.c"

int main()
{
    POINT p1, p2;
    GARIS L1, L2;
    float panjang, gradien;
    boolean ToF;

    p1 = MakePOINT(0, 0);
    p2 = MakePOINT(10, 10);
    MakeGARIS(p1, p2, &L1);
    BacaGARIS(&L2);
    TulisGARIS(L1);
    panjang = PanjangGARIS(L1);
    printf("\n%f\n", panjang);
    gradien = Gradien(L1);
    printf("%f", gradien);
    GeserGARIS(&L1, 10, 10);
    TulisGARIS(L1);

    MakeGARIS(p1, p2, &L2);
    ToF = IsSejajar(L1, L2);
    printf("\nSejajar : %d", ToF);

    p2 = MakePOINT(5, -4.999);
    MakeGARIS(p1, p2, &L2);
    ToF = IsTegakLurus(L1, L2);
    printf("\nTegak : %d", ToF);

    return 0;
}