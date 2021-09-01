#include <stdlib.h>
#include <stdio.h>
#include "time.c"

int main()
{
    //Declare
    boolean ToF;
    TIME waktu1, waktu2;
    long detik1, durasi;

    //istimevalid
    printf("Tes is Time Valid\n");
    ToF = IsTIMEValid(23, 59, 59);
    printf("23:59:59 %d\n", ToF);
    ToF = IsTIMEValid(24, 00, 00);
    printf("24:00:00 %d\n", ToF);

    //MakeTime
    printf("\nTes Make time, Baca Time & Tulis time\n");
    waktu1 = MakeTIME(23, 59, 59);
    //BacaTime
    BacaTIME(&waktu2);
    // TulisTime
    TulisTIME(waktu1);
    printf("\n");
    TulisTIME(waktu2);

    //Time to detik
    printf("\n\nTes time to detik & detik to time\n");
    detik1 = TIMEToDetik(waktu2);
    printf("Total detik: %ld", detik1);
    //detik to time
    waktu1 = DetikToTIME(86399);
    printf("\n");
    TulisTIME(waktu1);

    //booleanssss
    printf("\n\ntes boolean\n");
    //TEQ
    ToF = TEQ(waktu1, waktu2);
    TulisTIME(waktu1);
    printf(" == ");
    TulisTIME(waktu2);
    printf(" %d\n", ToF);
    //TNEQ
    ToF = TNEQ(waktu1, waktu2);
    TulisTIME(waktu1);
    printf(" != ");
    TulisTIME(waktu2);
    printf(" %d\n", ToF);
    //TLT
    ToF = TNEQ(waktu1, waktu2);
    TulisTIME(waktu1);
    printf(" < ");
    TulisTIME(waktu2);
    printf(" %d\n", ToF);
    //TNEQ
    ToF = TLT(waktu1, waktu2);
    TulisTIME(waktu1);
    printf(" > ");
    TulisTIME(waktu2);
    printf(" %d\n", ToF);

    //Next detik
    printf("\nTes Next & Previous detik\n");
    waktu2 = NextDetik(waktu1);
    TulisTIME(waktu2);
    //next n detik
    printf("\n");
    waktu2 = NextNDetik(waktu1, 86400);
    TulisTIME(waktu2);
    //prev detik
    printf("\n");
    waktu2 = PrevDetik(waktu1);
    TulisTIME(waktu2);
    //next prev n detik
    printf("\n");
    waktu2 = PrevNDetik(waktu1, 86400);
    TulisTIME(waktu2);

    //durasi
    printf("\n\nTes durasi");
    waktu1 = MakeTIME(22, 0, 0);
    waktu2 = MakeTIME(23, 0, 0);
    durasi = Durasi(waktu1, waktu2);
    printf("\n22:59:59 - 23:59:59 %ld", durasi);
    durasi = Durasi(waktu2, waktu1);
    printf("\n23:59:59 - 22:59:59 %ld", durasi);
}