#include "time.h"
#include <stdio.h>

/* KELOMPOK VALIDASI TERHADAP TYPE*/
boolean IsTIMEValid(int H, int M, int S)
{
    return ((H <= 23) && (H >= 0) && (M <= 59) && (M >= 0) && (S <= 59 && (S >= 0)));
};

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
TIME MakeTIME(int HH, int MM, int SS)
{
    TIME waktu;
    Hour(waktu) = HH;
    Minute(waktu) = MM;
    Second(waktu) = SS;
    return waktu;
};

/* KELOMPOK BACA/TULIS*/
void BacaTIME(TIME *T)
{
    int j, m, d;
    scanf("%d %d %d", &j, &m, &d);
    while (!IsTIMEValid(j, m, d))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &j, &m, &d);
    }
    *T = MakeTIME(j, m, d);
};

void TulisTIME(TIME T)
{
    printf("%d:%d:%d", T.HH, T.MM, T.SS);
};

long TIMEToDetik(TIME T)
{
    return (3600 * T.HH + 60 * T.MM + T.SS);
};

TIME DetikToTIME(long N)
{
    TIME waktu;
    if (N >= 86400)
    {
        N = N % 86400;
    }
    Hour(waktu) = (int)((N - (N % 3600)) / 3600);
    Minute(waktu) = (int)(((N - Hour(waktu) * 3600) - (N % 60)) / 60);
    Second(waktu) = (int)(N - Hour(waktu) * 3600 - Minute(waktu) * 60);
    return waktu;
};

/* KELOMPOK OPERASI TERHADAP TYPE*/
boolean TEQ(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
};

boolean TNEQ(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
};

boolean TLT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
};

boolean TGT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
};

/* *** Operator aritmatika TIME *** */
TIME NextDetik(TIME T)
{
    long seconds;
    seconds = TIMEToDetik(T);
    seconds += 1;
    return (DetikToTIME(seconds));
};

TIME NextNDetik(TIME T, int N)
{
    long seconds;
    seconds = TIMEToDetik(T);
    seconds += N;
    return (DetikToTIME(seconds));
};

TIME PrevDetik(TIME T)
{
    long seconds;
    seconds = TIMEToDetik(T);
    seconds -= 1;
    if (seconds < 0)
    {
        seconds = 86400 + seconds;
    }
    return (DetikToTIME(seconds));
};

TIME PrevNDetik(TIME T, int N)
{
    long seconds;
    seconds = TIMEToDetik(T);
    seconds -= N;
    if (seconds < 0)
    {
        seconds = 86400 + seconds;
    }
    return (DetikToTIME(seconds));
};

long Durasi(TIME TAw, TIME TAkh)
{
    long secondsAw, secondsAkh, durasi;
    secondsAw = TIMEToDetik(TAw);
    secondsAkh = TIMEToDetik(TAkh);
    if (secondsAkh >= secondsAw)
    {
        durasi = secondsAkh - secondsAw;
    }
    else
    {
        durasi = (86400 - secondsAw) + secondsAkh;
    }
    return durasi;
};