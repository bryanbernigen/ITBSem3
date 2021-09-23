/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 17 Septermber 2021
Topik praktikum : Matrix
Deskripsi       : prapraktikum untuk praktikum 5 pada 23 September 2021 dengan topik yang sama
*/

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
};

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j)
{
    return ((i >= 0) && (i < ROW_CAP) && (j >= 0) && (j < COL_CAP));
};

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
{
    //GIMANA KALO KOSONG????
    return (ROWS(m) - 1);
};
Index getLastIdxCol(Matrix m)
{
    return (COLS(m) - 1);
};
boolean isIdxEff(Matrix m, Index i, Index j)
{
    return ((i >= 0) && (i < ROWS(m)) && (j >= 0) && (j < COLS(m)));
};
ElType getElmtDiagonal(Matrix m, Index i)
{
    //Kalo kosong gimana??
    return (ELMT(m, i, i));
};

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
{
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    int i, j;
    for (i = 0; i < ROW_CAP; i++)
    {
        for (j = 0; j < COL_CAP; j++)
        {
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
};

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    CreateMatrix(nRow, nCol, m);
    int i, j, el;
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &el);
            ELMT(*m, i, j) = el;
        }
    }
};

void displayMatrix(Matrix m)
{
    int i, j;
    for (i = 0; i < ROWS(m); i++)
    {
        printf("%d", ELMT(m, i, 0));
        for (j = 1; j < COLS(m); j++)
        {
            printf(" %d", ELMT(m, i, j));
        }
        if (i != (ROWS(m) - 1))
        {
            printf("\n");
        }
    }
};

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    CreateMatrix(ROWS(m1), COLS(m1), &m3);
    int i, j;
    for (i = 0; i < ROWS(m1); i++)
    {
        for (j = 0; j < COLS(m1); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
};
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    CreateMatrix(ROWS(m1), COLS(m1), &m3);
    int i, j;
    for (i = 0; i < ROWS(m1); i++)
    {
        for (j = 0; j < COLS(m1); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
};
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix m3;
    CreateMatrix(ROWS(m1), COLS(m2), &m3);
    int i, j, k;
    int jumlah;
    for (i = 0; i < ROWS(m3); i++)
    {
        for (j = 0; j < COLS(m3); j++)
        {
            jumlah = 0;
            for (k = 0; k < COLS(m1); k++)
            {
                jumlah += (ELMT(m1, i, k) * ELMT(m2, k, j));
            }
            ELMT(m3, i, j) = jumlah;
        }
    }
    return m3;
};
Matrix multiplyConst(Matrix m, ElType x)
{

    Matrix m1;
    CreateMatrix(ROWS(m), COLS(m), &m1);
    int i, j;
    for (i = 0; i < ROWS(m); i++)
    {
        for (j = 0; j < COLS(m); j++)
        {
            ELMT(m1, i, j) = x * ELMT(m, i, j);
        }
    }
    return m1;
};
void pMultiplyConst(Matrix *m, ElType k)
{
    int i, j;
    for (i = 0; i < ROWS(*m); i++)
    {
        for (j = 0; j < COLS(*m); j++)
        {
            ELMT(*m, i, j) = k * ELMT(*m, i, j);
        }
    }
};

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
{
    boolean eq = true;
    int i, j;
    if (!isSizeEqual(m1, m2))
    {
        eq = false;
    }
    i = 0;
    while (eq && i < ROWS(m1))
    {
        j = 0;
        while (eq && j < COLS(m1))
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                eq = false;
            }
            j++;
        }
        i++;
    }
    return eq;
};

boolean isNotEqual(Matrix m1, Matrix m2)
{
    return (!isEqual(m1, m2));
};
boolean isSizeEqual(Matrix m1, Matrix m2)
{
    return ((ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2)));
};

/* ********** Operasi lain ********** */
int count(Matrix m)
{
    int jumlah;
    jumlah = ROWS(m) * COLS(m);
    return jumlah;
};

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    return (ROWS(m) == COLS(m));
};
boolean isSymmetric(Matrix m)
{
    boolean sym = true;
    if (!isSquare)
    {
        sym = false;
    }
    int i, j;
    i = 0;
    while (sym && (i < ROWS(m)))
    {
        j = 0;
        while (sym && (j < COLS(m)))
        {
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                sym = false;
            }
            j++;
        }
        i++;
    }
    return sym;
};
boolean isIdentity(Matrix m)
{
    boolean iden = true;
    if (!isSquare(m))
    {
        iden = false;
    }
    int i, j;
    i = 0;
    while (iden && (i < ROWS(m)))
    {
        j = 0;
        while (iden && (j < COLS(m)))
        {
            if (i == j)
            {
                if (ELMT(m, i, j) != 1)
                {
                    iden = false;
                }
            }
            else
            {
                if (ELMT(m, i, j) != 0)
                {
                    iden = false;
                }
            }
            j++;
        }
        i++;
    }
    return iden;
};
boolean isSparse(Matrix m)
{
    int jumlah, total;
    int i, j;
    jumlah = 0;
    total = count(m);
    for (i = 0; i < ROWS(m); i++)
    {
        for (j = 0; j < COLS(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                jumlah++;
            }
        }
    }
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    if ((20 * jumlah) <= total)
    {
        return true;
    }
    else
    {
        return false;
    }
};
Matrix inverse1(Matrix m)
{
    Matrix temp;
    CreateMatrix(ROWS(m), COLS(m), &temp);
    int i, j;
    for (i = 0; i < ROWS(m); i++)
    {
        for (j = 0; j < COLS(m); j++)
        {
            ELMT(temp, i, j) = -1 * ELMT(m, i, j);
        }
    }
    return temp;
};
void pInverse1(Matrix *m)
{
    int i, j;
    for (i = 0; i < ROWS(*m); i++)
    {
        for (j = 0; j < COLS(*m); j++)
        {
            ELMT(*m, i, j) *= -1;
        }
    }
};

// DETERMINAN AND FRIENDS
float determinant(Matrix m)
{
    int i, j, k, l, n;
    int temp;
    float det = 1;
    float pengali;
    float mat[ROWS(m)][COLS(m)];
    for (i = 0; i < ROWS(m); i++)
    {
        for (j = 0; j < COLS(m); j++)
        {
            mat[i][j] = ELMT(m, i, j);
        }
    }

    for (i = 0; i < ROWS(m); i++)
    {
        if (mat[i][i] == 0)
        {
            for (j = i + 1; j < ROWS(m); j++)
            {
                if (mat[j][i] != 0)
                {
                    break;
                }
            }
            if (j >= ROWS(m))
            {
                return 0;
            }
            else
            {
                for (k = 0; k < COLS(m); k++)
                {
                    temp = mat[i][k];
                    mat[i][k] = mat[j][k];
                    mat[j][k] = temp;
                }
                det *= -1;
            }
        }
        for (l = i + 1; l < ROWS(m); l++)
        {
            if (mat[l][i] != 0)
            {
                pengali = mat[l][i] / mat[i][i];
                for (n = 0; n < COLS(m); n++)
                {
                    mat[l][n] -= pengali * mat[i][n];
                }
            }
        }
    }
    for (i = 0; i < COLS(m); i++)
    {
        det *= mat[i][i];
    }
    return det;
}
void transpose(Matrix *m)
{
    Matrix temp;
    CreateMatrix(COLS(*m), ROWS(*m), &temp);
    int i, j;
    for (i = 0; i < ROWS(*m); i++)
    {
        for (j = 0; j < COLS(*m); j++)
        {
            ELMT(temp, j, i) = ELMT(*m, i, j);
        }
    }
    copyMatrix(temp, m);
};