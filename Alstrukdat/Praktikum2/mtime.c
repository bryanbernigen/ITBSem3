#include <stdio.h>
#include "time.c"

int main()
{
    int jumlah, terawal = 84600, terakhir = 0;
    TIME time1, time2;
    long durasitelp;
    //User diminta memasukkan jumlah data yang ada
    scanf("%d", &jumlah);
    //user diminta memasukkan time sebanyak jumlah data kali
    for (size_t i = 0; i < jumlah; i++)
    {
        printf("[%d]\n", i + 1);
        BacaTIME(&time1);
        BacaTIME(&time2);
        //jika waktu 1 lebih awal dari waktu 2
        if (TIMEToDetik(time1) < TIMEToDetik(time2))
        {
            durasitelp = Durasi(time1, time2);
            if (TIMEToDetik(time1) < terawal)
            {
                terawal = TIMEToDetik(time1);
            }
            if (TIMEToDetik(time2) > terakhir)
            {
                terakhir = TIMEToDetik(time2);
            }
        }
        //jika waktu 1 lebih akhir dari waktu 2
        else
        {
            durasitelp = Durasi(time2, time1);
            if (TIMEToDetik(time2) < terawal)
            {
                terawal = TIMEToDetik(time2);
            }
            if (TIMEToDetik(time1) > terakhir)
            {
                terakhir = TIMEToDetik(time1);
            }
        }
        printf("%ld\n", durasitelp);
    }
    //menampilkan waktu paling awal dan paling akhir
    time1 = DetikToTIME(terawal);
    time2 = DetikToTIME(terakhir);
    TulisTIME(time1);
    printf("\n");
    TulisTIME(time2);
}