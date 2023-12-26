// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 09/11/2023
// Topik pra-praktikum: listlinier
// Deskripsi: Realisasi remove.h

#include "remove.h"
#include<stdio.h>

void RemoveDuplicates(List *L) {
    // Dictionary
    List newl;
    address p, prec;
    // Algorithm
    CreateEmpty(&newl);
    
    p = First(*L);
    while (Next(p) != Nil)
    {
        prec = Next(p);
        if (Info(p) != Info(prec)) {
            InsVLast(&newl, Info(p));
        }
        p = Next(p);
    }
    InsVLast(&newl, Info(p));
}
/*
I.S. Variable L sudah terisi dengan nilai
Melakukan penghapusan apabila terdapat nilai yang sama

Contoh:
Input: [1,1,2,3]
Output: [1,2,3]

Input: [1,2,3,1]
Output: [1,2,3]
*/