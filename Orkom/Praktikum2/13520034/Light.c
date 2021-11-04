#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void illegal_move()
{
    printf("Dorrr....Anda Mati");
    exit(0);
};

void Light(char *input)
{
    char str_jawaban[51] = "You Have A Reason To Leave This Place, But I Don't.";
    char str_input[51];
    scanf("%s", str_input);
    if (strcmp(str_input, str_jawaban))
    {
        illegal_move();
    }
    return;
};