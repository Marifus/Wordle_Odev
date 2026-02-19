#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void KelimeSec(char* kelime_listesi[], int liste_uzunluk, char kelime[]);
int KontrolEt(char cevap[], char kelime[], char durum[], char olmayan_harf[], char yanlis_yer[]);
void AyirarakYaz(char str[]);

int main()
{
    srand(time(NULL));
    char* kelime_listesi[] = {"ROKET", "BILGISAYAR", "FARE", "KLAVYE", "EKRAN", };
    int liste_uzunluk = 5;
    char kelime[30];
    char olmayan_harf[30] = "";
    char yanlis_yer[30] = "";
    char cevap[30];
    char durum[30];

    KelimeSec(kelime_listesi, liste_uzunluk, kelime);
    int uzunluk = strlen(kelime);
    printf("\n%d harfli kelime secildi.\n", uzunluk);

    for (int i=0; i<uzunluk; i++) durum[i] = '_';
    durum[uzunluk] = '\0';

    do {
        printf("\n%d Harfli Tahminini Yaz: ", uzunluk);
        scanf("%s", cevap);
        for (int i=0; i<uzunluk; i++) cevap[i] = toupper(cevap[i]);
        cevap[uzunluk] = '\0';
     } while (KontrolEt(cevap, kelime, durum, olmayan_harf, yanlis_yer) != 1);


    return 0;
}

void KelimeSec(char* kelime_listesi[], int liste_uzunluk, char kelime[])
{
    int rastgele_sayi = rand() % liste_uzunluk;
    strcpy(kelime, kelime_listesi[rastgele_sayi]);
}

int KontrolEt(char cevap[], char kelime[], char durum[], char olmayan_harf[], char yanlis_yer[])
{
    if (strcmp(kelime, cevap) == 0)
    {
        printf("\nTebrikler! Dogru Cevabi Buldunuz: %s!", kelime);
        return 1;
    }

    else {
        int uzunluk = strlen(kelime);
        for (int i=0; i<uzunluk; i++)
        {
            if (kelime[i] == cevap[i]) durum[i] = cevap[i];
            else {
                if (strchr(kelime, cevap[i]) != NULL)
                {
                    if (strchr(yanlis_yer, cevap[i]) == NULL)
                    {
                        int n = strlen(yanlis_yer);
                        yanlis_yer[n] = cevap[i];
                        yanlis_yer[n+1] = '\0';
                    }
                }
                else if (strchr(olmayan_harf, cevap[i]) == NULL)
                {
                    int n = strlen(olmayan_harf);
                    olmayan_harf[n] = cevap[i];
                    olmayan_harf[n+1] = '\0';
                }
            }
        }
    }

    printf("\n%s- Yeri yanlis harfler: ", durum);
    AyirarakYaz(yanlis_yer);
    printf("- Olmayan harfler: ");
    AyirarakYaz(olmayan_harf);

    return 0;
}

void AyirarakYaz(char str[])
{
    int uzunluk = strlen(str);
    for (int i=0; i<uzunluk; i++)
    {
        printf("%c, ", str[i]);
    }
}