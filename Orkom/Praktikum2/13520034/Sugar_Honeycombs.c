#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void illegal_move(){
    printf("Dorrr....Anda Mati");
    exit(0);
};

void Sugar_Honeycombs(){
    int a1,a2,a3,a4,a5,a6;
    int i;
    scanf("%d %d %d %d %d %d",a1,a2,a3,a4,a5,a6);
    int arr[6] = {a1,a2,a3,a4,a5,a6};
    for ( i = 1; i < 6; i++)
    {
        if (arr[i]!=arr[i-1]+i)
        {
            illegal_move();
        }
    }
};