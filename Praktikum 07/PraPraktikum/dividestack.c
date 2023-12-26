// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 24/10/2023
// Topik pra-praktikum: stack
// Deskripsi: Realisasi dividestack.h

#include<stdio.h>
#include"dividestack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS) {
    // Dictionary
    Stack Stemp;
    int i;
    infotype val;
    // Algorithm
    CreateEmpty(&Stemp);
    for (i = 0; i <= (*s).TOP; i++) {
        Pop(s, &val);
        Push(&Stemp, val);
    }
    for (i = 0; i <= (Stemp).TOP+5; i++) {
        Pop(&Stemp, &val);
        if ((Stemp).T[i] % 2 == 0) {
            Push(evenS, val);
        } else {
            Push(oddS, val);
        }
    }
 // Di
}
/*
Memisahkan nilai genap dan nilai ganjil dari Stack s.

Awal:
s: 1,2,3,4
evenS:
oddS:

Akhir:
s: 
evenS 2,4
oddS: 1,3

Perhatikan order di dalam stacknya

*/
// Dictionary
//     Stack Stemp;
//     int i;
//     // Algorithm
//     CreateEmpty(&Stemp);
//     for (i = 0; i <= (*s).TOP; i++) {
//         Push(&Stemp, (*s).T[i]);
//         if ((Stemp).T[i] % 2 == 0) {
//             Push(evenS, (Stemp).T[i]);
//         } else {
//             Push(oddS, (Stemp).T[i]);
//         }
//     }