#include "RepeatElem.h"

void tranverse (int x, int a, int n, List *L, List *B) {
    // Dictionary
    boolean cari;
    int i;
    // Algorithm
    cari = true;
    for (i = a + 1; i < n; i++) {
        if (Get(*L, i) == x) {
            if (cari) {
                cari = false;
                Set(B, i, x);
            }
            Set(L, i, Mark);
        }
    }
}

void simplify (List *L) {
    // Dictionary 
    int move, cur, i;
    // Algorithm
    move = 0;
    for (i = 0; i< 100; i++) {
        cur = Get(*L, i);
        if (cur != Mark) {
            Set(L, i-move, cur);
            Set(L, i, (move? Mark : cur));
        } else {
            move++;
        }
    }
}

/*
Fungsi RepeatElem menerima satu buah argumen, yaitu sebuah pointer ke list L yang akan diperiksa bila ada anggotanya yang berulang.
Fungsi ini akan menghapus setiap pengulangan anggota yang sama pada L (jika ada) dan akan mengembalikan sebuah list baru L2 yang berisi
setiap anggota yang berulang tersebut (jika ada).
Jika ada anggota yang berulang lebih dari satu kali pada L, maka cukup isikan anggota tersebut satu kali saja ke L2 sehingga tidak ada
anggota yang berulang pada L2
*/
List RepeatElem(List *L) {
    // Dictionary
    List B;
    int n, i, cur;
    // Algorithm 
    B = MakeList();
    n = Length(*L);
    for (i = 0; i < n; i++) {
        cur = Get(*L, i);
        if (cur = Mark) continue;
        tranverse(cur, i, n, L, &B);
    }
    simplify(L);
    simplify(&B);
    return B;
}