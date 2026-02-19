#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void KelimeSec(char* kelime_listesi[], int liste_uzunluk, char kelime[]); //rand() fonksiyonu ile rastgele bir index seçilip strcpy() fonksiyonu ile kelime stringine eşlenecek.
int KontrolEt(char cevap[], char kelime[], char dogru_harf[], char yanlis_yer[]); //cevap doğruysa tebrikler mesajı ve 1 çıktısı verilecek, yanlışsa dogru_harf ve yanlis_yer dizileri güncellenip 0 çıktısı verilecek.
void AyirarakYaz(char str[]); //harfler tek tek araya , koyularak yazılacak.

int main()
{
    char* kelime_listesi[] = {"ROKET", "BILGISAYAR", "FARE", "KLAVYE", "EKRAN", };
    int liste_uzunluk = 5;
    char kelime[30];
    char dogru_harf[30] = "";
    char yanlis_yer[30] = "";
    char cevap[30];
    char durum[30];

    KelimeSec(kelime_listesi, liste_uzunluk, kelime);
    int uzunluk = strlen(kelime);
    printf("\n%d harfli kelime secildi!.\n");

    for (int i=0; i<uzunluk; i++) durum[i] = '_';
    durum[uzunluk] = '\0';

    do {
        printf("\n%d Harfli Tahminini Yaz: ", uzunluk);
        scanf("%s", cevap);
        for (int i=0; i<uzunluk; i++) cevap[i] = toupper(cevap[i]);
        cevap[uzunluk] = '\0';
     } while (KontrolEt(cevap, kelime, dogru_harf, yanlis_yer) != 1);


    return 0;
}