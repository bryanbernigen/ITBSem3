/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 11 November 2021
Topik praktikum : Binary Tree
Deskripsi       : praktikum 13 dengan topik yang sama
*/
#include "bintree.h"
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