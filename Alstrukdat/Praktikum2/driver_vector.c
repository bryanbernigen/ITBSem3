#include <stdio.h>
#include "vector.c"
#include "point.c"

int main()
{
    VECTOR vektor1, vektor2;
    float magnitude, dot, mult;
    vektor1 = MakeVector(0, 3);
    vektor2 = MakeVector(4, 0);
    TulisVector(vektor1);
    magnitude = Magnitude(vektor1);
    printf("\n%f", magnitude);
    vektor2 = Add(vektor1, vektor2);
    TulisVector(vektor2);
    vektor2 = Substract(vektor1, vektor2);
    TulisVector(vektor2);
    printf("\n\n");
    TulisVector(vektor1);
    TulisVector(vektor2);
    dot = Dot(vektor1, vektor2);
    printf("\n%f", dot);
    vektor2 = Multiply(vektor1, 10);
    TulisVector(vektor2);
    return 0;
}