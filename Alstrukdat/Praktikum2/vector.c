#include <stdio.h>
#include "vector.h"

VECTOR MakeVector(float x, float y)
{
    VECTOR vektor;
    AbsisComponent(vektor) = x;
    OrdinatComponent(vektor) = y;
    return vektor;
};

void TulisVector(VECTOR v)
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
};

float Magnitude(VECTOR v)
{
    return (Jarak0(v));
};

VECTOR Add(VECTOR a, VECTOR b)
{
    return (PlusDelta(a, AbsisComponent(b), OrdinatComponent(b)));
};

VECTOR Substract(VECTOR a, VECTOR b)
{
    return (PlusDelta(a, -AbsisComponent(b), -OrdinatComponent(b)));
};

float Dot(VECTOR a, VECTOR b)
{
    float hasil;
    hasil = AbsisComponent(a) * AbsisComponent(b);
    hasil += OrdinatComponent(a) * OrdinatComponent(b);
    return hasil;
};

VECTOR Multiply(VECTOR v, float s)
{
    AbsisComponent(v) = AbsisComponent(v) * s;
    OrdinatComponent(v) = OrdinatComponent(v) * s;
    return v;
};