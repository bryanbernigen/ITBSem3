/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 30 Septermber 2021
Topik praktikum : Mesin Kata
Deskripsi       : praktikum 6 pada 30 September 2021 dengan topik yang sama
*/

#include "tokenmachine.h"
#include "charmachine.h"
#include <stdio.h>

boolean endToken;
Token currentToken;

void ignoreBlank()
{
    while (currentChar == BLANK && currentChar != MARK)
    {
        adv();
    }
};

void startToken()
{
    start();
    ignoreBlank();
    if (currentChar == MARK)
    {
        endToken = true;
    }
    else
    {
        salinToken();
    }
    ignoreBlank();
};

void advToken()
{
    ignoreBlank();
    if (currentChar == MARK)
    {
        endToken = true;
    }
    else
    {
        salinToken();
    }
    ignoreBlank();
};

void salinToken()
{
    ignoreBlank();
    int temp;
    int count;
    switch (currentChar)
    {
    case '+':
        currentToken.tkn = '+';
        currentToken.val = -1;
        adv();
        break;
    case '-':
        currentToken.tkn = '-';
        currentToken.val = -1;
        adv();
        break;
    case '*':
        currentToken.tkn = '*';
        currentToken.val = -1;
        adv();
        break;
    case '/':
        currentToken.tkn = '/';
        currentToken.val = -1;
        adv();
        break;
    case '^':
        currentToken.tkn = '^';
        currentToken.val = -1;
        adv();
        break;
    default:
        temp = 0;
        count = 0;
        while (currentChar != BLANK && currentChar != MARK && count < CAPACITY)
        {
            temp += (int)currentChar - 48;
            temp *= 10;
            count++;
            adv();
        }
        temp /= 10;
        currentToken.tkn = 'b';
        currentToken.val = temp;
        break;
    }
    ignoreBlank();
};