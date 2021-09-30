/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 30 Septermber 2021
Topik praktikum : Mesin Kata
Deskripsi       : praktikum 6 pada 30 September 2021 dengan topik yang sama
*/

#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int geser;
    int i;
    char huruf;
    boolean first;
    startWord();
    geser = currentWord.length;
    first = true;
    while (!endWord)
    {
        if (!first)
        {
            printf(" ");
        }
        for (i = 0; i < currentWord.length; i++)
        {
            huruf = currentWord.contents[i];
            huruf += geser;
            while (huruf > 'Z')
            {
                huruf -= 26;
            }
            printf("%c", huruf);
        }
        advWord();
        first = false;
    }
    printf(".\n");
    return 0;
}