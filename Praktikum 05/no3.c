// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/11/2023
// Topik praktikum : mseinkata dan mesinkarakter
// Deskripsi : membuat program perbaikan keyboard

#include "mesinkata.h"
#include "mesinkarakter.h"

#include<stdio.h>

int main() {
    /* Dictionary */
    Word balik;
    int i, j;
    /* Algorithm */

    STARTWORD();
    while (!isEndWord())
    {
        balik = currentWord;
        for (i = 0; i < currentWord.Length; i++) {
            if (currentWord.TabWord[i] == ('q') || currentWord.TabWord[i] == ('w') || currentWord.TabWord[i] == ('r') || currentWord.TabWord[i] == ('t') || currentWord.TabWord[i] == ('y')) {
                for (j = 0; j < i; j++) {
                    balik.TabWord[j] = currentWord.TabWord[i-(j+1)];
                }
            }
            currentWord = balik;
            balik.TabWord[balik.Length] = '\0';
        }
        printf("%s", balik.TabWord);
        ADVWORD();
        
        if (isEndWord()) {
            printf(".\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}