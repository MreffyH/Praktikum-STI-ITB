// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 17/10/2023
// Topik praktikum: Querry
// Deskripsi: Realisasi reverse.h

#include<stdio.h>
#include "reverse.h"

// void Push (Queue *q, ElType x) {
//     if (IsEmpty(*q)) {
//         IDX_HEAD(*q) = 0;
//         IDX_TAIL(*q)= 0; 
//     } else {
//         IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % IDX_MAX;
//     }
//     (*q).Tab[IDX_TAIL(*q)] = x;
// }

// ElType Front (Queue q) {
//     return (q.Tab[IDX_HEAD(q)]);
// }

void transferReverse(Queue* q1, Queue* q2)
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
{
    // Dictionary
    int i, j;
    ElType initiallength;
    // Algorithm
    i = 0;
    initiallength = Length(*q1) - 1; // supaya length awal tdk berubah
    while (i < initiallength) 
    {
        j = 0;
        while (j < (Length(*q1) - 1)) 
        {
            enqueue(q1, dequeue(q1));
            j++;
        }
        enqueue(q2, dequeue(q1));
        i++;
    }
    enqueue(q2, dequeue(q1));
}


// j
// 12345
// 23451
// 34512
// 45123
// 51234

// i
// 54321

// for i 
// {
//     for j
// }

// i = IDX_TAIL(*q1);
//     do {
//         Push(q2, (*q1).Tab[i]);
//         i = (i - 1 + Length(*q1)) % Length(*q1);
//     } while (i != IDX_HEAD(*q1));
//     Push(q2, Front(*q1));