#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void illegal_move()
{
    printf("Dorrr....Anda Mati");
    exit(0);
};

void Tug_of_War(char *input)
{
    int a1, a2;
    int hasil;
    int len;
    len = sscanf(input, "%d %d", &a1, &a2);
    if (len <= 1)
    {
        illegal_move();
    }
    hasil = 0;
    switch (a1)
    {
    case 0:
        hasil = 0xb0;
    case 1:
        hasil -= 0x1bd;
    case 2:
        hasil += 0x29d;
    case 3:
        hasil -= 0x2bf;
    case 4:
        hasil += 0x2bf;
    case 5:
        hasil -= 0x2bf;
    case 6:
        hasil += 0x2bf;
    case 7:
        hasil -= 0x2bf;
        break;
    default:
        illegal_move();
    }
    if (a1 > 5)
    {
        illegal_move();
    }
    if (hasil != a2)
    {
        illegal_move();
    }
    return;
};