// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 29/11/2023
// Topik praktikum : variasi list linier
// Deskripsi : realisasi swap.h

#include"swap.h"

#include<stdio.h>

address AddressAtIndex(List L, infotype x)
/* 
Mencari address suatu node pada element ke- X
*/
{
    /* Dictionary */
    address p;
    int i;
    /* Algorithm */
    p = First(L);

    i = 1;
    while (p != Nil && i < x)
    {
        p = Next(p);
        i++;
    }
    return p;
}

void Swap(List *L1)
/*
Kondisi awal: L1 sudah terisi dengan beberapa node.
Lakukan swap node pada node yang ada di tengah dari suatu List
*/
{
    /* Dictionary */
    address p1, p2, temp;
    int x, y;
    /* Algorithm */
    scanf("%d %d", &x, &y);

    p1 = AddressAtIndex(*L1, x);
    p2 = AddressAtIndex(*L1, y);

    if (Next(p1) == p2) {
        Next(p1) = Next(p2);
        Prev(p2) = Prev(p1);
        
        if (Next(p1) != NULL) {
            Prev(Next(p1)) = p1;
        } 
        if (Prev(p2) != NULL) {
            Next(Prev(p2)) = p2;
        }
        
        Next(p2) = p1;
        Prev(p1) = p2;

    } else if (Next(p2) == p1) {
        Next(p2) = Next(p1);
        Prev(p1) = Prev(p2);
        
        if (Next(p2) != NULL) {
            Prev(Next(p2)) = p2;
        } 
        if (Prev(p1) != NULL) {
            Next(Prev(p1)) = p1;
        }
        
        Next(p1) = p2;
        Prev(p2) = p1;

    } else {
        temp = Next(p1);
        Next(p1) = Next(p2);
        Next(p2) = temp;

        temp = Prev(p1);
        Prev(p1) = Prev(p2);
        Prev(p2) = temp;

        if (Next(p1) != NULL) {
            Prev(Next(p1)) = p1;
        }
        if (Prev(p1) != NULL) {
            Next(Prev(p1)) = p1;
        }

        if (Next(p2) != NULL) {
            Prev(Next(p2)) = p2;
        }
        if (Prev(p2) != NULL) {
            Next(Prev(p2)) = p2;
        }
    }
    
    if (First(*L1) == p1) {
        First(*L1) = p2;
    } else if (First(*L1) == p2) {
        First(*L1) = p1;
    }

    if (Last(*L1) == p1) {
        Last(*L1) = p2;
    } else if (Last(*L1) == p2) {
        Last(*L1) = p1;
    }
}