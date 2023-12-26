// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/10/2023
// Topik praktikum : stack
// Deskripsi : membuat realisasi krabbypatty.h

#include "krabbypatty.h"
#include<stdio.h>

void krabbyPatty(Stack *ingredients, Stack *burger) {
    // Dictionary
    Stack x; 
    int top, bot, cur;
    // Algorithm
    top = 0;
    bot = 0;
    CreateEmpty(&x);
    while (!IsEmpty(*ingredients))
    {
        Pop(ingredients, &cur);
        if(cur == 0) {
            bot = 1;
        } else if(cur == 9) {
            top = 1;
        } else {
            Push(&x, cur);
        }

        if (top * bot) {
            break;
        }
    }
    if (top * bot) {
        Push(burger, 0);
        while (!IsEmpty(x))
        {
            cur; 
            Pop(&x, &cur);
            Push(burger, cur);
        }
        Push(burger, 9);
    }   
}
/*
Membuat satu Krabby Patty dari tumpukan bahan

~ CONTOH 1 ~
Awal:
ingredients -> [7, 1, 9, 2, 3, 4, 3, 0, 1, 2]
burger -> []

Akhir:
ingredients -> [7, 1]
burger -> [0, 2, 3, 4, 3, 1, 2, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- keju
- patty
- selada
- bawang
- selada
- keju
- roti bawah

Sisa bahan di tumpukan bahan:
- patty
- saus

~ CONTOH 2 ~
Awal:
ingredients -> [0, 2, 9, 3, 4, 3, 7, 0, 9, 9]
burger -> []

Akhir:
ingredients -> [0, 2, 9, 3, 4, 3, 7]
burger -> [0, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- roti bawah

Sisa bahan di tumpukan bahan:
- saus
- selada
- bawang
- selada
- roti atas
- keju
- roti bawah

~ CONTOH 3 ~
Awal:
ingredients -> [1, 3, 8, 5, 7, 9]
burger -> []

Akhir:
ingredients -> []
burger -> []

Terjemahan:
Krabby Patty tidak dapat dibuat

Tidak ada bahan tersisa di tumpukan bahan
*/