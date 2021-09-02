#include <stdlib.h>
#include <stdio.h>
#include "point.c"

int main()
{
    //declare
    POINT p1, p2;
    boolean ToF;
    int kuadran;
    float jarak;

    //make point
    printf("Tes buat point + nampilin\n");
    p1 = MakePOINT(1, 1);
    //baca point
    BacaPOINT(&p2);
    //tulis poin
    TulisPOINT(p1);
    printf("\n");
    TulisPOINT(p2);

    //booleanssss
    printf("\n\ntes booleansss\n");
    p2 = MakePOINT(0, 0);
    printf("p1 = ");
    TulisPOINT(p1);
    printf("\np2 = ");
    TulisPOINT(p2);
    //EQ
    ToF = EQ(p1, p2);
    printf("\np1 = p2 %d\n", ToF);
    //NEQ
    ToF = NEQ(p1, p2);
    printf("p1 != p2 %d\n", ToF);
    //origin
    ToF = IsOrigin(p1);
    printf("p1 di (0,0) %d\n", ToF);
    //di sbx
    ToF = IsOnSbX(p1);
    printf("p1 di (x,0) %d\n", ToF);
    //disby
    ToF = IsOnSbY(p1);
    printf("p1 di (0,y) %d\n", ToF);

    //kuadran
    printf("\n tes kuadran\n");
    p1 = MakePOINT(1, 1);
    kuadran = Kuadran(p1);
    printf("%d", kuadran);
    p1 = MakePOINT(1, -1);
    kuadran = Kuadran(p1);
    printf(" %d", kuadran);
    p1 = MakePOINT(-1, 1);
    kuadran = Kuadran(p1);
    printf(" %d", kuadran);
    p1 = MakePOINT(-1, -1);
    kuadran = Kuadran(p1);
    printf(" %d", kuadran);

    //next and prev
    printf("\n\ntes next and prev\n");
    p1 = MakePOINT(1, 1);
    //nextx
    p1 = NextX(p1);
    //nexty
    p1 = NextY(p1);
    TulisPOINT(p1);
    printf("\n");
    //plus delta
    p1 = PlusDelta(p1, 8, 8);
    TulisPOINT(p1);
    printf("\n");
    //Mirror
    p1 = MirrorOf(p1, 1);
    TulisPOINT(p1);
    printf("\n");
    p1 = MirrorOf(p1, 0);
    TulisPOINT(p1);
    printf("\n");

    //Jarak-jarakan
    printf("\ntes jarak geser dan putar\n");
    //jarak ke origin
    jarak = Jarak0(p1);
    printf("%f\n", jarak);
    //jarak 2 titik
    p2 = MakePOINT(5, 5);
    jarak = Panjang(p1, p2);
    printf("%f\n", jarak);
    //geser
    Geser(&p2, 5, 5);
    TulisPOINT(p2);
    printf("\n");
    //geser ke sbx
    GeserKeSbX(&p1);
    TulisPOINT(p1);
    printf("\n");
    //geser ke sb y
    GeserKeSbY(&p1);
    TulisPOINT(p1);
    printf("\n");
    //mirror
    Mirror(&p2, 1);
    TulisPOINT(p2);
    printf("\n");
    Mirror(&p2, 0);
    TulisPOINT(p2);
    printf("\n");
    Putar(&p2, 270);
    TulisPOINT(p2);
    printf("\n");
}