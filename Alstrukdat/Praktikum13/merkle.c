/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 11 November 2021
Topik praktikum : Binary Tree
Deskripsi       : praktikum 13 dengan topik yang sama
*/
#include "bintree.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void invertBtree(BinTree *p)
{
    /* I.S. Pohon p terdefinisi */
    /* F.S. Pohon p diflip secara vertikal */
    /*      Contoh:
               1
             2   5
            3 4 6
            Menjadi:
               1
             5   2
              6 4 3 */
    BinTree tempkiri, tempkanan;
    if (!isTreeEmpty(*p))
    {
        tempkiri = LEFT(*p);
        tempkanan = RIGHT(*p);
        LEFT(*p) = tempkanan;
        RIGHT(*p) = tempkiri;
        if (tempkiri != NULL)
        {
            invertBtree(&tempkiri);
        }
        if (tempkanan != NULL)
        {
            invertBtree(&tempkanan);
        }
    }
};
int main()
{
    int n;
    int tempn;
    int i;
    int k;
    ElType val;
    Address addr1, addr2;
    Address left, right;
    BinTree p;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Jumlah masukan tidak sesuai\n");
    }
    else
    {
        tempn = n - 1;
        if (n & tempn)
        {
            printf("Jumlah masukan tidak sesuai\n");
        }
        else
        {
            Address arr[n];
            for (i = 0; i < n; i++)
            {
                scanf("%d", &val);
                arr[i] = newTreeNode(val);
            }
            if (n == 1)
            {
                CreateTree(ROOT(arr[0]), NULL, NULL, &p);
            }
            else
            {
                while (n > 2)
                {
                    i = 0;
                    k = 0;
                    for (i = 0; i < n; i += 2)
                    {
                        addr1 = arr[i];
                        addr2 = arr[i + 1];
                        val = ROOT(addr1) + ROOT(addr2);
                        arr[k] = NewTree(val, addr1, addr2);
                        k++;
                        left = addr1;
                        right = addr2;
                    }
                    n /= 2;
                }
                addr1 = arr[0];
                addr2 = arr[1];
                val = ROOT(addr1) + ROOT(addr2);
                CreateTree(val, addr1, addr2, &p);
            }
            invertBtree(&p);
            printTree(p, 2);
        }
    }
    return 0;
}