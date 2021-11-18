/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 18 November 2021
Topik praktikum : List Rekursif
Deskripsi       : praktikum 12 dengan topik yang sama
*/

#include "listrec.c"
#include <stdio.h>

List splitEvenIndex(List l)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    List temp;
    if (isEmpty(l))
    {
        return l;
    }
    else
    {
        if (isEmpty(tail(l)))
        {
            return tail(l);
        }
        else
        {
            temp = konso(splitEvenIndex(tail(tail(l))), head(tail(l)));
            return temp;
        }
    }
};

List splitOddIndex(List l)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    List temp;
    if (isEmpty(l))
    {
        return l;
    }
    else
    {
        if (isEmpty(tail(l)))
        {
            return konso(tail(l), head(l));
        }
        else
        {
            temp = konso(splitOddIndex(tail(tail(l))), head(l));
            return temp;
        }
    }
};

List splitBeforeX(List l, ElType x)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada pada list, maka
kembalikan list l.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    List temp;
    if (isEmpty(l))
    {
        return l;
    }
    else
    {
        if (head(l) != x)
        {
            temp = konso(splitBeforeX(tail(l), x), head(l));
            return temp;
        }
        else
        {
            return NULL;
        }
    }
};

List reverseList(List l)
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list l.
Jika l kosong, kembalikan list kosong. */
{
    List temp;
    if (isEmpty(l))
    {
        return l;
    }
    else
    {
        temp = konsb(reverseList(tail(l)), head(l));
    }
    return temp;
};

int main()
{
    List l = NULL;
    char op;
    int k;
    scanf(" %c", &op);
    while (op != 'X')
    {
        switch (op)
        {
        case 'F':
            scanf("%d", &k);
            l = konso(l, k);
            break;
        case 'B':
            scanf("%d", &k);
            l = konsb(l, k);
            break;
        case 'O':
            l = splitOddIndex(l);
            break;
        case 'E':
            l = splitEvenIndex(l);
            break;
        case 'R':
            l = reverseList(l);
            break;
        case 'P':
            scanf("%d", &k);
            l = splitBeforeX(l, k);
            break;
        default:
            break;
        }
        scanf(" %c", &op);
    }
    if (isEmpty(l))
    {
        printf("Semua gugur\n");
    }
    else
    {
        displayList(l);
    }
    return 0;
}
