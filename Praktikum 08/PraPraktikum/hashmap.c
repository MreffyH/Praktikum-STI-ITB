// NIM: 18222103
// Nama: Muhammad Reffy Haykal
// Tanggal: 24/10/2023
// Topik pra-praktikum: set & map
// Deskripsi: Realisasi hashmap.h

#include "hashmap.h"
#include<stdio.h>

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M) {
    address idx;
    M->Count = Nil;
    for (idx = 0; idx < MaxEl; idx++) {
        M->Elements[idx].Key = Undefined;
        M->Elements[idx].Value = Undefined;
    }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K) {
    return K % MaxEl;
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k) {
    boolean found = false;
    address idx = Hash(k);
    while (found == false && idx < MaxEl && M.Elements[idx].Key != Undefined) 
    {
        if (M.Elements[idx].Key == k) {
            found = true;
        } else {
            idx++;
        }
    }
    if (found == true) {
        return M.Elements[idx].Value;
    } else {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v) {
    boolean found = false;
    address idx = Hash(k);

    while (found == false && idx < MaxEl && M->Elements[idx].Key != Undefined) 
    {
        if (M->Elements[idx].Key == k) {
            found = true;
        } else {
            idx++;
        }
    }
    if (found == false && M->Elements[idx].Key == Undefined) {
        M->Elements[idx].Key = k;
        M->Elements[idx].Value = v;
        M->Count++;
    }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */