#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void illegal_move()
{
    printf("Dorrr....Anda Mati");
    exit(0);
};

void read_six_numbers(char *input, char *arr);

void Sugar_Honeycombs(char *input)
{
    int i;
    read_six_numbers(char input, char *arr);
    for (i = 1; i < 6; i++)
    {
        if (arr[i] != arr[i - 1] + i)
        {
            illegal_move();
        }
    }
    return;
};