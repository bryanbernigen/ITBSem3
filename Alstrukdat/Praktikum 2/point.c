#include "point.h"
#include <math.h>

POINT MakePOINT(float X, float Y)
{
    POINT p;
    Absis(p) = X;
    Ordinat(p) = Y;
    return p;
};

void BacaPOINT(POINT *P)
{
    float x, y;
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x, y);
};

void TulisPOINT(POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
};

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ(POINT P1, POINT P2)
{
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
};

boolean NEQ(POINT P1, POINT P2)
{
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
};

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin(POINT P)
{
    return ((Absis(P) == 0.0) && (Ordinat(P) == 0.0));
};

boolean IsOnSbX(POINT P)
{
    return (Absis(P) == 0.0);
};

boolean IsOnSbY(POINT P)
{
    return (Ordinat(P) == 0.0);
};

int Kuadran(POINT P)
{
    if (Absis(P) > 0.0)
    {
        if (Ordinat(P) > 0.0)
        {
            return 1;
        }
        else
            return 4;
    }
    else
    {
        if (Ordinat(P) > 0.0)
        {
            return 2;
        }
        else
            return 3;
    }
};

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX(POINT P)
{
    POINT p;
    Absis(p) = Absis(P) + 1;
    Ordinat(p) = Ordinat(P);
    return p;
};

POINT NextY(POINT P)
{
    POINT p;
    Ordinat(p) = Ordinat(P) + 1;
    Absis(p) = Absis(P);
    return p;
};

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    POINT p;
    Absis(p) = Absis(P) + deltaX;
    Ordinat(p) = Ordinat(P) + deltaY;
    return p;
};

POINT MirrorOf(POINT P, boolean SbX)
{
    POINT p;
    if (SbX)
    {
        Absis(p) = Absis(P);
        Ordinat(p) = -Ordinat(P);
        return p;
    }
    else
    {
        Absis(p) = -Absis(P);
        Ordinat(p) = Ordinat(P);
        return p;
    }
};

float Jarak0(POINT P)
{
    float jarak;
    jarak = sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
    return jarak;
};

float Panjang(POINT P1, POINT P2)
{
    float jarak;
    jarak = sqrt(pow((Absis(P1) - Absis(P2)), 2) + pow((Ordinat(P1) - Ordinat(P2)), 2));
    return jarak;
};

void Geser(POINT *P, float deltaX, float deltaY)
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
};

void GeserKeSbX(POINT *P)
{
    Ordinat(*P) = 0.0;
};

void GeserKeSbY(POINT *P)
{
    Absis(*P) = 0.0;
};

void Mirror(POINT *P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(*P) = -Ordinat(*P);
    }
    else
    {
        Absis(*P) = -Absis(*P);
    }
};

void Putar(POINT *P, float Sudut)
{
    float xlama = Absis(*P);
    float ylama = Ordinat(*P);
    float rad = -Sudut * M_PI / 180;
    Absis(*P) = xlama * cos(rad) + ylama * -sin(rad);
    Ordinat(*P) = xlama * sin(rad) + ylama * cos(rad);
};