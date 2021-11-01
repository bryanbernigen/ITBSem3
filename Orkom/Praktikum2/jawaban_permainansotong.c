#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void illegal_move(){
    printf("Dorrr....Anda Mati");
    exit(0);
};


void Light(){
    char str_jawaban[51] ="You Have A Reason To Leave This Place, But I Don't.";
    char str_input[51];
    scanf("%s",str_input);
    if(strcmp(str_input,str_jawaban)){
        illegal_move();
    }
};

void Sugar_Honeycombs(){
    int a1,a2,a3,a4,a5,a6;
    int i;
    scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6);
    int arr[6] = {a1,a2,a3,a4,a5,a6};
    for ( i = 1; i < 6; i++)
    {
        if (arr[i]!=arr[i-1]+i)
        {
            illegal_move();
        }
    }
};

void Tug_of_War(){
    int a1,a2;
    int hasil;
    scanf("%d %d",&a1,&a2);
    hasil=0;
    switch (a1)
    {
    case 0:
        hasil=0xb0;
    case 1:
        hasil-=0x1bd;
    case 2:
        hasil+=0x29d;
    case 3:
        hasil-=0x2bf;
    case 4:
        hasil+=0x2bf;
    case 5:
        hasil-=0x2bf;
    case 6:
        hasil+=0x2bf;
    case 7:
        hasil-=0x2bf;
        break;
    default:
        illegal_move();
    }
    if (a1>5)
    {
        illegal_move();
    }
    if(hasil!=a2){
        illegal_move();
    }
    
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

int main(){
    Tug_of_War();
    printf("nais");
}