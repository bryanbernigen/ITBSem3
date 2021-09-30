/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 24 Septermber 2021
Topik praktikum : Matrix
Deskripsi       : prapraktikum untuk praktikum 6 pada 29 September 2021 dengan topik yang sama
*/

#include "wordmachine.h"
#include <stdio.h>

boolean endWord;
Word currentWord;

void ignoreBlank()
{
    while (currentChar == BLANK && currentChar != MARK)
    {
        adv();
    }
};

void startWord()
{
    start();
    ignoreBlank();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        copyWord();
    }
    ignoreBlank();
};

void advWord()
{
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        copyWord();
    }
    ignoreBlank();
};

void copyWord()
{
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && i < CAPACITY)
    {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = i;
};