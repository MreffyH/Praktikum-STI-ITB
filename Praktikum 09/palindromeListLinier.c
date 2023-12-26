// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/11/2023
// Topik praktikum : List Linier
// Deskripsi : realisasi palindromeListLinier.h
#include "palindromeListLinier.h"

#include<stdio.h>
#include<stdlib.h>

boolean isPalindromeList(List l)
/*
    Diberikan sebuah list linier l,
    kembalikan true jika list tersebut merupakan palindrome dan false jika tidak.
    Contoh input/output:
    l: [1,2,3,4,5,4,3,2,1]
    expected return: true

    Di atas merupakan palindrome list linier karena jika dibaca dari kiri maupun kanan, tetap sama.

    l: [1,1,2,1]
    expected return: false

    Di atas bukan palindrome list linier karena jika dibaca dari kiri maupun kanan, berbeda. 1,1 dan 1,2.

    P.S. List linier kosong merupakan palindrome.
*/
{
    /* Dictionary */
    address p, q;
    List temp, kiri, kanan;
    int tengah, i, val;

    boolean palindrom = true;
    /* Algorithm */
    CreateEmpty(&temp);
    CreateEmpty(&kiri);
    CreateEmpty(&kanan);

    temp = l;
    tengah = NbElmt(l) / 2;

    if (!IsEmpty(l)) {
        for (i = 0; i < tengah; i++) {
            DelVFirst(&temp, &val);
            InsVLast(&kiri, val);
            DelVLast(&temp, &val);
            InsVLast(&kanan, val);
        }

        p = First(kiri);
        q = First(kanan);

        for (i = 0; i < tengah; i++) {
            if (Info(p) != Info(q)) {
                palindrom = false;
            }
            p = Next(p);
            q = Next(q);
        }
    }
    return palindrom;
}