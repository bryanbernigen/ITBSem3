#include <stdio.h>
#include "garis.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
void MakeGARIS(POINT P1, POINT P2, GARIS *L)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
};

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS(GARIS *L)
{
    POINT point1, point2;
    BacaPOINT(&point1);
    BacaPOINT(&point2);
    while (EQ(point1, point2))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&point1);
        BacaPOINT(&point2);
    }
    MakeGARIS(point1, point2, L);
};

void TulisGARIS(GARIS L)
{
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
};

float PanjangGARIS(GARIS L)
{
    return (Panjang(PAwal(L), PAkhir(L)));
};

float Gradien(GARIS L)
{
    return ((Ordinat(PAkhir(L)) - (Ordinat(PAwal(L)))) / ((Absis(PAkhir(L))) - (Absis(PAwal(L)))));
};

void GeserGARIS(GARIS *L, float deltaX, float deltaY)
{
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
};

boolean IsTegakLurus(GARIS L1, GARIS L2)
{
    float gradien1, gradien2;
    gradien1 = Gradien(L1);
    gradien2 = Gradien(L2);
    if ((1 + (gradien1 * gradien2)) < __FLT_EPSILON__)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

boolean IsSejajar(GARIS L1, GARIS L2)
{
    float gradien1, gradien2;
    gradien1 = Gradien(L1);
    gradien2 = Gradien(L2);
    return (gradien1 == gradien2);
};