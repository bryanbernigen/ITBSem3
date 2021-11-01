#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void illegal_move(){
    printf("Dorrr....Anda Mati");
    exit(0);
};

void Glass(){
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[16]={10,2,14,7,8,12,15,11,0,4,1,13,3,9,6,5};
    int banyak_ngulang=1;
    int jumlah=0;
    while (arr[a]!=15)
    {
        jumlah+=arr[a];
        a=arr[a];
        banyak_ngulang+=1;
    }
    if (banyak_ngulang!=15)
    {
        illegal_move();
    }
    if (b!=jumlah)
    {
        illegal_move();
    }
    ;
}