// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 09/11/2023
// Topik pra-praktikum: listlinier
// Deskripsi: Realisasi oddevenlist.h

#include "OddEvenList.h"
#include<stdio.h>

void Sorting(List *l) {
    // Dictionary
    List temp;
    address p, last, prec;
    // Algorithm
    CreateEmpty(&temp);
    
    while(!IsEmpty(*l)) 
    {
        last = AdrMax(*l);
        prec = First(*l);
        p = First(*l);
        while (p != last) 
        {
            prec = p;
            p = Next(p);
        }
        if (p == prec) {
            DelFirst(l, &last);
        } else {
            DelAfter(l, &last, prec);
        }
        InsertFirst(&temp, last);
    }
    First(*l) = First(temp);
}

void OddEvenList(List L, List *Odd, List *Even) {
    // Dictionary
    address p;
    // Algorithm
    CreateEmpty(Odd);
    CreateEmpty(Even);

    p = First(L);
    while (p != Nil) {
        if (Info(p) % 2 == 0) {
            InsVFirst(Even, Info(p));
        } else {
            InsVFirst(Odd, Info(p));
        }
        p = Next(p);
    }
    Sorting(Odd);
    Sorting(Even);
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/