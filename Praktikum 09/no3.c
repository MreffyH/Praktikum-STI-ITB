// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/11/2023
// Topik praktikum : List Linier
// Deskripsi : realisasi program menebak lagu

#include "listlinier.h"

#include<stdio.h>

int main() {
    /* Dictionary */
    List L, tempL;
    int n, x, count, length;
    /* Algorithm */
    CreateEmpty(&L);
    CreateEmpty(&tempL);
    
    count = 0;

    scanf("%d", &n);

    while (n != -99)
    {
        InsVLast(&L, n);
        scanf("%d", &n);
    }

    length = NbElmt(L);

    scanf("%d", &x);

    while (count < length && Search(L, x) != Nil)
    {
        if (Search(tempL, x) == Nil) {
            InsVLast(&tempL, x);
            count++;
        }
        if (count != length)
        {
            scanf("%d", &x);
        }
    }

    if (count == length) {
        printf("Berhasil menebak %d lagu\n", length);
    } else {
        printf("Poser! %d tidak ada di dalam album\n", x);
    }
}