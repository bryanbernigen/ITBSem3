#include "matrix.c"

int main()
{
    Matrix m, m1, m2;
    boolean ToF;
    Index idx;
    ElType el;
    float determinan;
    readMatrix(&m, 3, 3);
    determinan = determinant(m);
    printf("%f", determinan);
    return 0;
}