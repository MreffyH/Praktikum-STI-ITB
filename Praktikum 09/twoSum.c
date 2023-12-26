// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/11/2023
// Topik praktikum : List Linier
// Deskripsi : realisasi twoSum.h

#include"twoSum.h"

#include<stdio.h>
#include<stdlib.h>

int twoSum(List L1, List L2)
/* I.S. Masing-masing elemen dari L1 dan L2 merupakan angka dan */
/* L1 maupun L2 tidak kosong */
/* F.S. Menghasilkan angka hasil penjumlahan dua buah list L1 dan L2 */

/* Contoh */
/* L1 = 1 -> 2 -> 3  = 321 */ 
/* L2 = 5 -> 4 = 45 */
/* maka hasilnya adalah */
/* 321 + 45 = 366 */

/* L1 = 1 -> 9 -> 9 */
/* L2 = 9 */
/* maka hasilnya adalah */
/* 991 + 9 = 1000 */
{
    /* Dictionary */
    address p, q;
    int sum1, sum2, tempnilai1, tempnilai2;
    /* Algorithm */
    p = First(L1);
    q = First(L2);
    sum1 = 0;
    sum2 = 0;
    tempnilai1 = 1;
    tempnilai2 = 1;

    while (p != Nil) 
    {
        sum1 += (Info(p) * tempnilai1);
        tempnilai1 *= 10;
        p = Next(p);
    }

    while (q != Nil) 
    {
        sum2 += (Info(q) * tempnilai2);
        tempnilai2 *= 10;
        q = Next(q);
    }

    return (sum1 + sum2);
}