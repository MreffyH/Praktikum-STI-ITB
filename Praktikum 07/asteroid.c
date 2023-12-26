// NIM : 18222103
// Nama : Muhammad Reffy Haykal
// Tanggal : 30/10/2023
// Topik praktikum : stack
// Deskripsi : realisasi asteroid.h

#include <stdio.h>
#include <math.h>
#include "asteroid.h"

boolean isCollision(infotype a, infotype b) {
    return (a > 0) && (b < 0);
}
/* Mengirim true jika terjadi tabrakan */
/* yaitu ketika a > 0 dan b < 0 */

void collision(int n, infotype *asteroids, Stack *remaining) {
    Push(remaining, asteroids[0]);
    for(int i = 1; i < n; i++)
    {
        if(!isCollision(InfoTop(*remaining), asteroids[i])) {
            Push(remaining, asteroids[i]);
        } else {
            int push = 0;
            while (isCollision(InfoTop(*remaining), asteroids[i]) && !IsEmpty(*remaining))
            {
                int x = abs(InfoTop(*remaining));
                int y = abs(asteroids[i]);
                
                if(x > y) {
                    break;
                } else if(x < y) {
                    int dump; 
                    Pop(remaining, &dump);
                    push = 1;
                } else {
                    int dump; 
                    Pop(remaining, &dump);
                    break;
                }
            } 
            if (push) {
                Push(remaining, asteroids[i]);
            }
        }
    }
}
/* Proses: Mengisi stack dengan asteroid yang tersisa setelah tabrakan. 
    Asteroid dengan ukuran lebih besar tidak akan hancur, dan apabila kedua asteroid ukurannya sama maka 
    akan sama-sama hancur.  */
/* I.S Array asteroids pasti terisi dengan elemen positif atau negatif, Stack remaining telah terbentuk */
/* F.S Stack remaining terisi oleh sisa asteroid yang tidak hancur */
/*
   Contoh simulasi:
   - Input: [5,10,-5]
     Output: [5,10]
     Penjelasan: 5(->) 10(->) -5(<-) Asteroid 5 dan 10 bergerak ke kanan, -5 ke kiri. Asteroid 10 lebih besar dari -5, sehingga -5 hancur.

   - Input: [-10,10]
     Output: [-10,10]
     Penjelasan: -10(<-) 10(->) Kedua asteroid bergerak ke arah berbeda dan tidak bertemu, jadi tidak ada yang hancur.

   - Input: [1,-2,10,5]
     Output: [-2,10,5]
     Penjelasan: 1(->) -2(<-) akan bertabrakan, namun asteroid -2 lebih besar sehingga asteroid 1 hancur. Lalu, -2(<-) 10(->) tidak akan bertabrakan. 5 tetap melaju karena bergerak ke arah yang sama.
*/

void displayAsteroids(Stack S) {
    if(IsEmpty(S)) {
        printf("[]\n");
        return;
    }
    Stack copy; 
    CreateEmpty(&copy);
    while (!IsEmpty(S)) 
    {
        int cur; 
        Pop(&S, &cur);
        Push(&copy, cur);
    }
    printf("[");
    int dump; 
    Pop(&copy, &dump);
    printf("%d", dump);
    while (!IsEmpty(copy))
    {
        Pop(&copy, &dump);
        printf(",%d", dump);
    }
    printf("]\n");
}
/* Proses : mereverse isi stack dari parameter kemudian mencetak elemen-elemen stack tersebut ke layar. */
/* I.S. S boleh kosong */
/* F.S. Jika S tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen asteroid bernilai 4, 5, -2 akan dicetak: [-2,4,5] */
/* Jika Stack kosong : menulis [] */
/* Terdapat new line setelah kurung tutup */
/* Hint: Buatlah stack baru untuk meng-copy isi dari stack parameter */